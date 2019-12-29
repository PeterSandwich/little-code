#include "test.h"


char* add_person(struct person one){
    char *ret = (char*)malloc(100);
    bzero(ret, 100);
    sprintf(ret,"add successfully! number: %d, name: %s, age: %d, sex: %s",
	one.no, one.info->name,one.info->age,(one.info->sex == 1 ? "man":"women"));
    return ret;
}

struct base* new_base(struct base in){
    struct base* b = (struct base*)malloc(sizeof(struct base));
    b->name = in.name;
    b->age = in.age;
    b->sex = in.sex;
    return b;
}

struct person* new_person(struct person in){
    struct person* one = (struct person*)malloc(sizeof(struct person));
    one->info = in.info;
    one->no = in.no;
    return one;
}

void test_callback(fn f, int n){
    printf("[IN C]entry C callback function\n");
	int ret = f(n);
	printf("[IN C]C callback function bye. the ret is %d\n",ret);
}
