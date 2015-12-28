#include <stdio.h>

main () {
    int c; 
    static char buf[BUFSIZ];

    printf("BUFSIZ is %d\n!", BUFSIZ);

    setbuf (stdout, buf);
    
    while ( (c = getchar()) != EOF) 
        putchar(c);
}

