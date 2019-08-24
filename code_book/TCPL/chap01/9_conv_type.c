#include <stdio.h>
#include <ctype.h>

int main() {
    char a = 'A';
    a = tolower(a);
    printf("n: %c\n", a);
    if (isdigit(a))
        printf("a is a digit\n");
    else 
        printf("a is not a digit\n");
    return 0;
}