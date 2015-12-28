#include "apue.h"
#include "my_err.h"
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf	jmpbuffer;
static int		globvar;

int
main(void)
{
	int					autovar;
	register	int		regivar;
	volatile	int		volavar;
	static 		int 	statvar;

	globvar = 1; autovar = 2; regivar = 3; volavar = 4; statvar = 5;
	if(setjmp(jmpbuffer) != 0) {
		printf("after longjmp:\n");
		printf("globvar = %d; autovar = %d; regivar = %d; volavar = %d; statvar = %d;\n",
			globvar, autovar, regivar, volavar, statvar );
		exit(0);
	}

	globvar = 91; autovar = 92; regivar = 93; volavar = 94; statvar = 95;
	f1(autovar, regivar, volavar, statvar);
	exit(0);

}

static void 
f1(int i, int j, int k, int l)
{
	printf("in f1():\n");
	printf("globvar = %d; autovar = %d; regivar = %d; volavar = %d; statvar = %d;\n",
			globvar, i, j, k, l );
	f2();
}

static void
f2(void)
{
	longjmp(jmpbuffer, 1);
}