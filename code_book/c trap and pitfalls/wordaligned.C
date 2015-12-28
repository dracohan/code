#include <stdio.h>

main() {
    struct A { 
    char a; 
    char a1[2];
    short b; 
    int c; 
    };
    
    struct B { 
    char d[5]; 
    short e;
    short f[3];
    int g;
    };

    int szA = sizeof(struct A);
    int szB = sizeof(struct B);

    printf("sizeof A is %d\n", szA);
    printf("sizeof B is %d\n", szB);
    //printf("sizeof c is %d\n!", sizeof(c));
    //printf("sizeof d is %d\n!", sizeof(d));
    //printf("sizeof e is %d\n!", sizeof(e));
    //printf("sizeof f is %d\n!", sizeof(f));
    //printf("sizeof g is %d\n!", sizeof(g));

}
