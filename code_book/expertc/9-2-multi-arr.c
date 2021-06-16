#include <stdio.h>

int main() {
    int apricot[2][3][5];
    int (*r)[5] = apricot[0];
    int *t = apricot[0][0];

    printf("sizeof apr[0]: %d\n", sizeof(apricot[0]));
    printf("sizeof *r: %d\n", sizeof(r[0]));
    printf("sizeof *r: %d\n", sizeof(r[0]));
    //printf("r: %p\n", r++);
    //printf("t: %p\n", t++);

    
    //printf("r: %p\n", r++);
    //printf("t: %p\n", t++);
    return 0;
}

