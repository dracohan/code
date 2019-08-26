#include <stdio.h>

int main() {
    printf("gogoog\n");
    char* s = "hello, world";
    printf(":%s:\n", s);
    printf(":%-15s:\n", s);
    printf(":%15s:\n", s);
    return 0;
}