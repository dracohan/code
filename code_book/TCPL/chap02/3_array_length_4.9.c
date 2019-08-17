#include <stdio.h>

int main(){
    char a[] = {'a', 'b', 'c', 'd'};
    a[1] = 'e';
    printf("next item: %d\n", a[5]);
    for (int i = 0; i < 4; i++) {
        printf("next item: %c\n", a[i]);
        a[i] = i;
    }
}