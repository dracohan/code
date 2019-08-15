#include <stdio.h>

#define MAXLINE 1000

getline(char s[]) {
    int i, c;
    for (i = 0; (c = getchar()) != 'q'; i++){
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    //s[i] = '\0';
    return i;
}

  
main() {
    int i;
    char input[MAXLINE];
    getline(input);
    printf("Input is: %s", input);
    char out[20];
    for (i = 0; i < 10; i++){
        out[i] = 'a';
    }
    printf("out: %s", out);
}