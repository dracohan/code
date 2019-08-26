#include <stdio.h>

int main() {
    char first[10], second[10];
    printf("gogoog\n");
    char* s = "hello, world";
    sscanf(s, "h%s %s", first, second);
    printf("1: %s 2: %s", first, second);
    return 0;
}