#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef int(*fn)(int);

struct base{
    char *name;
    int age;
    int sex;
};

struct person{
    int no;
    struct base* info;
};

char* add_person(struct person one);
struct base* new_base(struct base in);
struct person* new_person(struct person in);
void test_callback(fn f, int n);
int callback_test_c(int num);