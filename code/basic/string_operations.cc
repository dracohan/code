#include <iostream>
#include <assert.h>
using namespace std;

int mystrlen(const char* str)
{
	int length = 0;
	while(*str++ != '\0')
		length++;
	return length;
}

char* mystrcpy(char* dst, const char* src)
{
	assert(dst != NULL && src != NULL);
	if(dst == src)
		return dst;
	char* ret = dst;
	while((*dst++=*src++)!='\0');
	return ret;
}

//字符串比较，p>q则返回整数，p=q返回0，否则返回负数
int mystrcmp(const char* str1, const char* str2)
{
	while(*str1 && *str1 == *str2)
		str1++, str2++;
	return (int) ((unsigned char) *str1 - (unsigned char) *str2);
}
// 找到字符c在字符串s中首次出现的位置
char* mystrstr(const char* s, char c)
{
	for(; *s; s++)
		if(*s == c)
			return (char*) s;
	return NULL;
}

//拼接字符串，注意这里dst需要保证有足够的空间
char* mystrcat(char* dst, const char* src)
{
	char* ret = dst;
	while(*dst)
		dst++;
	while((*dst++ = *src++) != '\0')
		;
	return ret;
}


int
main()
{
	char cstr[] = "123456789";
	int length = mystrlen(cstr);
	cout << "length of cstr is:" << length << endl;

	char* dst = new char[40];
	
	cout << "the content of dst after mystrcpy is: " << mystrcpy(dst, cstr) << endl;

	cout << "the result of mystrcmp(dst, cstr) is: " << mystrcmp(dst, cstr) << endl;

	cout << "the position of 4 is cstr is: " << mystrstr(cstr, '4') << endl;

	cout << "the result of mystrcat(dst, cstr) is: " << mystrcat(dst, cstr) << endl;
}