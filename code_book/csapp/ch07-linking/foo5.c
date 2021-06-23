#include <stdio.h>

void f(void);

int x = 15212;
int y = 15213;


int main() {
    f();
    printf("&x = %x, &y = %x\n", &x, &y);
    printf("x = %x, y = %x\n", x, y);
    return 0;
}


