#include <stdio.h>

int main() {
    printf("go\n");
    char (*(*x[3])())[5];
    x = f;
    return 0;
}

char f(){
    return 'c';
}

