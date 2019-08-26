#include <string.h>
#include "utils.h"

void mreverse(char s[]) {
    int c, i, j;
    for (i =0, j = strlen(s)-1; i<j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

/* squeeze: delete all c from s */
void msqueeze(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

void mstrcat(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
    s[i] = '\0';
}

int mstrindex(char s[], char t[]) {
    int i, j ,k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int mstrcmp(char* s, char* t){
    int i;
    
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

int main() {
    int n;
    char s1[MAXTOKEN] = "abc";
    char s2[MAXTOKEN] = "def";
    mstrcat(s1, s2);
    n = mstrlen("helloworld");
    printf("new s1: %s\n", s1);
    printf("len: %d\n", n);
}

