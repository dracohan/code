#include <stdio.h>
#include <string>
// using namespace std;

int strlen(char* ch){
    int i;
    if (ch == NULL) {
        return 0;
    }
    for (i = 0; ch[i] != '\0'; i++){}
    return i;
}
int main() {
    char* c = "hello";
    printf(c);
    printf("%d", strlen(c));

    return 0;
}