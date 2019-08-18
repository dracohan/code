int ustrlen(char *s) {
    int n; 
    for (n = 0; *s != '\0'; s++) 
        n++;
    return n;
}

int ustrindex(char s[], char t[]) {
    int i, j ,k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

void ustrcat(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
    s[i] = '\0';
}

void usqueeze(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c ) {
            s[j++] = c;
        }
        s[j] = '\0';
    }
}