#include "String.h"
#include <iostream>
#include <string.h>
#include <iomanip>
#include <assert.h>

using namespace std;

//io operation
ostream& 
operator<<(ostream& os, String& str)
{
	return os << str.c_str();
}
istream&
operator>>(istream& is, String& str)
{
	const int limit_string_size = 4096;
	char inBuf[limit_string_size];

	is >> setw(limit_string_size) >> inBuf;

	str = inBuf;
	return is;
}
//constractor
String::String(){
	_size = 0;
	_string = 0;
}
String::String(const char* s)
{
	if(!s) {
		_size = 0; _string = 0;}
	else {
		_size = strlen(s)	;
		_string = new char[_size + 1];
		strcpy(_string, s);
	}
}
String::String(const String& rhs)
{
	_size = rhs._size;
	if(!rhs._string){
		_string = 0; }
	else {
		_string = new char[_size + 1];
		strcpy(_string, rhs._string);
	}
}
String::~String(){
	delete[] _string;
}

inline String& 
String::operator=(const char* s)
{
	delete[] _string;
	if (!s) {
		_size = 0;
		_string = 0;
	}
	else {
		//cout << "operator= invoked for char: " << *s << endl;
		_size = strlen(s);
		_string = new char[_size + 1];
		strcpy(_string, s);
	}
	return *this;
}
inline String& 
String::operator=(const String& rhs)
{
	if (this != &rhs)
	{
		delete[] _string;
		if(!rhs._string) {
			_size = 0;
			_string = 0;
		}
		else {
			_size = rhs._size;
			_string = new char[_size + 1];
			strcpy(_string, rhs._string);
		}
	}
	else {
		return *this;
	}
}
//+= operator
inline String& 
String::operator+=(const char* s)
{
	if(s)
	{
		String tmp(*this);

		//assign a space for the new string
		_size += strlen(s);
		delete[] _string;
		_string = new char[_size + 1];

		//copy
		strcpy(_string, tmp._string);
		strcpy(_string + tmp._size, s);
	}
	return *this;
}
inline String& 
String::operator+=(const String& rhs)
{
	if (rhs._string)
	{
		String tmp(*this);

		_size += rhs._size;
		delete _string;
		_string = new char[_size + 1];

		strcpy(_string, tmp._string);
		strcpy(_string + tmp._size, rhs._string);
	}
	return *this;
}
char& 
String::operator[](const int index) const
{
	assert(index > 0 && index < _size);
	return _string[index];
}
