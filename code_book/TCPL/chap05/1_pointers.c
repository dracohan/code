#include <stdio.h>

int main() {
    int i;
    printf("i: %d\n", i);
    printf("&i: %#x\n", &i);
    printf("size of i: %llu\n", sizeof(i));
    printf("size of i: %llu\n", sizeof(&i));

    int* p = &i;
    p++;
    printf("p: %#x\n", p++);
    printf("*p: %#x\n", *p);
    printf("p: %#x\n", p++);
    printf("*p: %#x\n", *p);
    printf("p: %#x\n", p++);
    printf("*p: %#x\n", *p);
    printf("p: %#x\n", p++);
    printf("*p: %#x\n", *p);
} 