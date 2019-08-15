#include <stdio.h>
#include <ctype.h>

int main() {
    char a = '1';
    a = tolower(a);
    printf("n: %c\n", a);
    printf("isdigit: %d\n", isdigit(a));
}