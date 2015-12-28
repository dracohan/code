#include <stdio.h>

char* string1, *string2;

int main () {
	/* var definition */
	string1 = "abcd"; string2 = "abcd";
	//string1[0] = '1'; /* RUN-TIME ERROR POssiBLE */

	/* function call */
	if (string1 ==string2) printf("String is shared\n");
	else printf("String is no shared\n");

	if (*string1 == '1') printf("String is variable\n");
	else printf("String is not variable\n");

	return 0;
	
}
