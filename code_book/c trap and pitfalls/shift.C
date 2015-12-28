#include <stdio.h>

main () {
    int a = 1; 
    unsigned b = 1;

    int c = -1; 
    char d = (int)511;

    printf("%d\n", d);
    printf("%d\n", 'A');

    a = a<<1;
    b = b<<1;
    c = c<<1;
    d = d<<1; // a is decimal 97, bin 1100001

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);


}

