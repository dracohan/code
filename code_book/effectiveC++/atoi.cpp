#include <stdio.h>
#include <string.h>
#include <ctype.h> 

/* atoi: convert an string to int */
int _atoi (char s[]) 
{
	int i = 0, delta = 1;
	for (int j = strlen(s) -1; j >= 0; j--) {
		i = i+ (s[j] - '0')*((j == strlen(s) - 1) ? 1 : delta);
		delta = delta * 10;
	}
	return i;
}


/* atoi:  convert s to integer; version 2 */ 
int atoi(char s[]) 
{ 
	int i, n, sign; 

	for (i = 0; isspace(s[i]); i++)  /* skip white space */ 
		; 
	sign = (s[i] == '-') ? -1 : 1; 
	if (s[i] == '+' || s[i] == '-')  /* skip sign */ 
		i++; 
	for (n = 0; isdigit(s[i]); i++) 
		n = 10 * n + (s[i] - '0'); 
	return sign * n; 
} 

void main ()
{
	int i = 0; 
	char s[] = "1234";
	i = atoi(s);
	printf ("%d", i);
}

