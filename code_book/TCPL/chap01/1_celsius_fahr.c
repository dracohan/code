/* convert fahr to celsius
 * 2012-12-26
*/ 

#include <stdio.h> 
#define UPPER 300
#define LOWER 0
#define STEP 20 

int main ()
{
	int fahr;
	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3d %8.2f\n", fahr, 5.0* (fahr - 32) / 9.0);
	return 1;
}
