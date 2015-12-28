#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_byte(byte_pointer start, int len) {
	int i; 
	for (i =0; i < len; i++) {
//		printf(" %d", start);
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_int(int x) {
		printf(" %08x", &x);
	show_byte((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
		printf(" %08x", &x);
	show_byte((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
		printf(" %08x", &x);
	show_byte((byte_pointer) &x, sizeof(void *));
}

int main () {
	int i = 18;
	float f = 3.14;
	void *x = "a";
	const char *s = "abcdef";

	show_byte((byte_pointer) s, strlen(s));

	float *pf = &f;
	printf(" %f", *pf);
	//puts('10');
	printf("\n");

	printf("value of i is %d\n", i);
	printf("value of i is %d after cast to float\n", (float) i);

	show_int(i);
	show_float((float) i);
	show_pointer((void *) &i);
}
