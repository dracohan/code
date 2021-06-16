#include <stdio.h>

void funca(double a[]) {
    printf("funca:\n");
    printf("&ca: %p\n", &a);
    printf("&(ca[0]): %p\n", &(a[0]));
    printf("&(ca[1]): %p\n", &(a[1]));
}


void funcb(double *pa) {
    printf("funcb:\n");
    printf("&ca: %p\n", &pa);
    printf("&(ca[0]): %p\n", &(pa[0]));
    printf("&(ca[1]): %p\n", &(pa[1]));
    printf("++pa: %p\n", ++pa);
}

double ga[] = {1,2,3,4};

int main() {
    double f;
    printf("double size: %d\n", sizeof(f));
    funca(ga);
    funcb(ga);
    return 0;
}

