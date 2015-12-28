///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   atoi_itoa.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2014/07/06 23:36
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h> // printf
#include <ctype.h> // isspace(), isdigit()

int atoi(char s[])
{
	int i, n, sign;
	//skip the space
	for(i=0; isspace(s[i]); i++)
		;
	//store the sign
	sign = (s[i] == '-') ? -1 : 1;
	//skip the sign
	if(s[i] == '+' || s[i] == '-')
		s++;
	//calculate the number
	for(n = 0; isdigit(s[i]); i++)
		n = 10*n + (s[i] - '0');
	return sign * n;
}

void itoa(int n, char s[])
{
	int i, j, sign;
	if((sign = n ) < 0)
		n = -n;
	i = 0;
	do{
		s[i++] = n%10 + '0';
	}while(n /= 10 > 0);

	if(sign < 0)
		s[i++] = '-1';
	s[i] = '0';
	for(j = i; j >= 0; j--)
		printf("%c", s[j]);
}

int main()
{
	int i = 0;
	char s[] = "1234";
	i = atoi(s);
	printf("The atoi of \"1234\" is: %d", i);

	int j = 5678;
	char t[10];
	itoa(j, t);

	return 0;
}
	
	
