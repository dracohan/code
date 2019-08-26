#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect{
    struct point pt1;
    struct point pt2;
};

int main(){
    struct point a, b, c;
    a.x = 1;
    a.y = 2;
    struct rect screen;
    printf("pt: %#X\n", screen.pt1.y);
    return 0;
}