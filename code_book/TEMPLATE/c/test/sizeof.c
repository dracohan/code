#include <stdio.h>

typedef int INT;

typedef struct point{
    int i;
    int j;
    char c;
}pt;

union upt
{
    /* data */
    int i;
    int j;
    double f;
    char c;
} u;


typedef struct {}ept;

int main() {
    printf("hello\n");
    int n[] = {1,2,3};
    double d[] = {0, 0, 0};
    printf("sizeof n: %d\n", sizeof(n));

    INT I = 1;
    printf("sizeof int: %d\n", sizeof(int));
    printf("sizeof unsigned: %d\n", sizeof(unsigned));
    printf("sizeof long: %d\n", sizeof(long));
    printf("sizeof float: %d\n", sizeof(float));
    printf("sizeof double: %d\n", sizeof(double));
    printf("sizeof union: %d\n", sizeof(u));
    printf("sizeof I: %d\n", sizeof(I));
    printf("sizeof pt: %d\n", sizeof(pt));
    printf("sizeof ept: %d\n", sizeof(ept));
    printf("sizeof int array: %d\n", sizeof(n));
    printf("sizeof double array: %d\n", sizeof(d));

    pt p1, p2; 

    return 0;
}