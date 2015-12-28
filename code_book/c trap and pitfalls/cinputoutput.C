#include "stdio.h"

int main (){
    char h;
    int a = 0;
    char c;
    printf("add of h is 0x%08x. \n", &h);
    printf("add of a is 0x%08x. \n", &a);
    printf("add of c is 0x%08x. \n", &c);

    while (a < 5){
        scanf("%d", &c);
        printf("%d\n", a);
        a++;
    }
    printf("\n");
}

