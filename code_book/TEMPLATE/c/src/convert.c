#include <ctype.h>
#include "utils.h"

#define MAX 100

int atoi(char s[]) {
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for(n = 0; isdigit(s[i]); i++) {
        n = 10 * n + (s[i] - '0');
    }
    return sign * n;
}

void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int lower(int c) {
    if (c > 'A' && c < 'Z') {
        return c + ('a' - 'A');
    } else {
        return c;
    }
}

int main() {
    int i = 1234;
    char s[MAX];
    itoa(i, s);
    printf("s: %s\n", s);
}

