///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   strcpy test.cc
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/11
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
int main() {
	char string[11], str1[11];
	int i;
	for(i=0; i<10; i++)
	{
		str1[i] = 'a';
	}
	str1[i] = '\0';
	
	
	strcpy( string, str1 );
	printf("string: %s\nstr1: %s\n", string, str1);
	/*

	char str1[]="Sample string";
  char str2[40];
  char str3[40];
  strcpy (str2,str1);
  strcpy (str3,"copy successful");
  printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
	*/
 
	return 0;
}

