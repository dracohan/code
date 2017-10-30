void strcat(char s[], char t[]) {
    int i, j;
    i =j = 0;
    while (s[i] != '0')
        i++;
    while (s[j] != '0')
        s[i++] = s[j++];
    s[i] = '\0';
}

