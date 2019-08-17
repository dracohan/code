#include <stdio.h>

int func1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int func2(unsigned word) {
    return ((int) word << 24) >> 24;
}

int main() {
    int intx = 0x00000076;
    int inty = 0x87654321;
    int intz = 0x000000C9;
    int intw = 0xEDCBA987;
    printf("func1 of %x is %x, func2 of %x is %x\n", intx, func1(intx),\
    intx, func2(intx)); 
    printf("func1 of %x is %x, func2 of %x is %x\n", inty, func1(inty),\
    inty, func2(inty)); 
    printf("func1 of %x is %x, func2 of %x is %x\n", intz, func1(intz),\
    intz, func2(intz)); 
    printf("func1 of %x is %x, func2 of %x is %x\n", intw, func1(intw),\
    intw, func2(intw)); 
}

