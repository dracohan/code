#include <stdio.h>

typedef struct {
    unsigned int is_keyword :   1;
    unsigned int is_extern :   1;
    unsigned int is_static :   1;
}flags;

int main(){
    printf("gogoog\n");
    flags f1;
    f1.is_extern = 1;
    f1.is_static = 1;
    f1.is_keyword = 1;
    printf("%d\n", f1);
    return 0;
}