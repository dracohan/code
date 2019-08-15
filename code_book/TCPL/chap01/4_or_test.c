#include <stdio.h>

f() {
    printf("in f()\n");
    return 0;
}

main() {
    int i = 0;
    if (i == 1 || f()) {
        printf("%d\n", i);
    }
}

