#include <stdio.h>

int f(){
    static int i; 
    printf("current i: %d\n", i++);
}

int main() {
    int i; 
    for (i = 0; i < 10; i++) {
        f();
    }
}