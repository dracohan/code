#include <stdio.h>

// print the 9*9 squares
int main () {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) 
			printf("%d\t", i*j);
		printf("\n");
	}
}
