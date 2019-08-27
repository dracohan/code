#include <stdio.h>
#include <ctype.h>

#define BUFSIZ 100

int getchar() {
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {
        n = read(0, buf, sizeof(buf));
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int main() {
    int c;
    while ((c = getchar()) != EOF)
        putchar(tolower(c));
    return 0;
}

