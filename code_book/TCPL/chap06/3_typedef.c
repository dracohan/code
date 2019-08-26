#include <stdio.h>

typedef int a_shit;

typedef struct tnode* Treeptr;

typedef struct tnode{
    char* word;
    int count;
    Treeptr left;
    Treeptr right;
} Treenode;

int main() {
    a_shit a;
    printf("shit");
    printf("a_shit: %d", a);
    return 0;
}