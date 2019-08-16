#include <stdio.h>

void strcat(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
    s[i] = '\0';
}

int main() {
    char* s1 = "abc";
    char* s2 = "def";
    strcat(s1, s2);
    printf(s1);
}