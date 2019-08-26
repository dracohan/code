#include <string.h>
#include "utils.h"

void mstrcopy(char* to, char* from)
{
	while (*to = *from)
		;
}

int mstrlen(char *s) {
    int n; 
    for (n = 0; *s != '\0'; s++) 
        n++;
    return n;
}

void mstrcat(char* dst, char* src){
    while(*dst)
        dst++;
    while (*dst++ = *src++)
        ;
    *dst = '\0';
}

int mstrcmp(char* s, char* t) {
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int main() {
    //string cat
    char s1[10] = "abc";
    char* s2 = "abcd";
    // mstrcat(s1, s2);
    // printf("new s1: %s\n", s1);

    //string compare
    printf("compare: %d\n", mstrcmp(s1, s2));
}

