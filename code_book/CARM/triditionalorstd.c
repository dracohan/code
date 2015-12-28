#include <stdio.h>

#define K 0xFFFFFFFF /* -1 in 32bit */

int main () {
	if (0<K) printf("K is unsigned (Standard C)\n");
	else printf ("K is signed (Triditional C)\n");
	return 0;
}
