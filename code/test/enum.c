#include <stdio.h>

typedef enum {
    a = 2,
    b,
    c,
} test;

typedef enum {
    d = 2,
    e,
    f,
    g = 6,
    h,
    i = 4,
    j,
    k,
    l = 10,
    m,
    n,
} test1;

int main() {
    printf("gogogo\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("d: %d\n", d);
    printf("e: %d\n", e);
    printf("f: %d\n", f);
    printf("g: %d\n", g);
    printf("h: %d\n", h);
    printf("i: %d\n", i);
    printf("j: %d\n", j);
    printf("k: %d\n", k);
    printf("l: %d\n", l);
    printf("m: %d\n", m);
    printf("n: %d\n", n);
    return 0;
}