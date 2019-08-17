#include "../common_header/utils.h"

void print_array(int v[]){
    if (v == NULL)
        return;
    int i, l;
    l = sizeof(v)/sizeof(v[0]);
    printf("len: %d\n", l);
    for (i = 0; i < 9; i++ ){
        printf("%d\n", v[i]);
    }
}