#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y){
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2) {
    p1.x = p2.x;
    p1.y = p2.y;
    return p1;
}

int main() {
    printf("go\n");
    struct point pt, origin, *pp;
    origin = makepoint(2,3);
    printf("pt.x: %d, pt.y: %d\n", pt.x, pt.y);
    printf("origin.x: %d, origin.y: %d\n", origin.x, origin.y);
    pp = &origin;
    pp->x = 10;
    printf("origin.x: %d, origin.y: %d\n", origin.x, origin.y);

    return 0;
}