#include <stdio.h>
#define IN 1
#define OUT 0

main() {
	int nc, nw, nl, c;
	nc = nl = nw =0;
	while ((c=getchar()) != EOF) {
		if (c == '\n') { 
			nl++;
			nw++;
		}
		if (c == ' ') 
			nw++;
		else
			nc++;
	}

printf("nc = %d, nw = %d, nl = %d \n", nc, nw+1, nl+1);

}
