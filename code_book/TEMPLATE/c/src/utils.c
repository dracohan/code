#include <stdio.h>
#include <string.h>

void print_array(int v[], int length){
    int i;
    if (!v)
        return;
    printf("len: %lu\n", sizeof(v));
    for (i = 0; i < length; i++ ){
        printf("%d\n", v[i]);
    }
}
