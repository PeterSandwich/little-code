package main

/*
#cgo CFLAGS: -I ./
#cgo LDFLAGS: -L ./ -ltest
#include "test.h"
*/
import "C"

import (
	"fmt"
	"unsafe"
)

func main(){
	fmt.Println("\n========结构体指针传递测试========")
	test1()
	fmt.Println("\n==========c 回调 go 测试==========")
	test2()
}

func test1(){
	// 定义base结构体
	base := C.struct_base{name: C.CString("pan jiawei"), age: C.int(21), sex: C.int(1)}
	// 取回base的新对象指针
	p_base := C.new_base(base)

	person := C.struct_person{no: C.int(123), info: p_base}
	// p_info := C.new_person(person)

	ret := C.add_person(person)
	fmt.Println(C.GoString(ret))	
}

func test2(){
	C.test_callback((C.fn)(unsafe.Pointer(C.callback_test_c)), 66)
}

//export callback_test
func callback_test(num int)int{
	fmt.Println("[IN GO] callback function be called")
	return num*100
}

