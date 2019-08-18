#include <stdio.h>
#include <string.h>
#include "../common_header/utils.h"

void print_array(int v[], int length){
    int i;
    if (!v)
        return;
    printf("len: %llu\n", strlen(v));
    for (i = 0; i < length; i++ ){
        printf("%d\n", v[i]);
    }
}

