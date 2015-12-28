#include <stdio.h>
/* original version 
void printd(long d) {
   
    if (d < 0) {
        putchar ('-');
        d = -d;
    }
    if (d / 10)
        printd (d / 10);
    //putchar (d % 10 + '0');
    putchar ("0123456789"[d % 10]);
} 
*/

// Second Version 
void printneg (int d);

void printd (int d) {
    if (d <0) {
        putchar ('-');
        printneg (d);
    }
    else
        printneg (-d);
}

void printneg (int d) {
    if (d <= -10)
        printneg (d/10);
    putchar ("0123456789"[-(d % 10)]);
}

int main () {
    int a = 20;
    int b = 303;
    int c = -10;
    int d = -2147483648; //max value for 4bytes int

    printd(a);
    puts("");
    printd(b);
    puts("");
    printd(c);
    puts("");
    printd(d);
    puts("");
    putchar(10);
    printf("\nc in original format: %d!\n", c);
    printf("The decimal format of '0' is: %d!\n", '0');
    printf("The decimal format of 'a' is: %d!\n", 'a');
    printf("The decimal format of 'A' is: %d!\n", 'A');

}

