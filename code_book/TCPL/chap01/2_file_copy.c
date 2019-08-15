#include <stdio.h>

main() {
    int c;
    c = getchar();
    while(c != EOF) {
        putchar(46);
        c = getchar();
    }
}

