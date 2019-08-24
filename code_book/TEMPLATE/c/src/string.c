#include <string.h>
#include <stdio.h>

void reverse(char s[]) {
    int c, i, j;
    for (i =0, j = strlen(s)-1; i<j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

void strcat(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
    s[i] = '\0';
}

void strcopy(char* to, char* from)
{
	while (*to = *from)
		;
}

int strindex(char s[], char t[]) {
    int i, j ,k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strlen(char *s) {
    int n; 
    for (n = 0; *s != '\0'; s++) 
        n++;
    return n;
}

int main() {
    char* s1 = "abc";
    char* s2 = "def";
    strcat(s1, s2);
    printf(s1);
}

