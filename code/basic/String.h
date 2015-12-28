///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   String.h
//  Version     :   0.10	created	2014/05/24 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
using namespace std;

//为了输入输出操作符
class String;

class String {
	friend istream& operator>>( istream& is, String& S);
	friend ostream& operator<<( ostream& os, String& S);
public:
	//String str1;
	//String str2("abcd");
	//String str3(str2);
	String();
	String(const char*);
	String(const String&);

	~String();

	inline bool operator==(char const *s) const;
	inline bool operator==(String const &rhs) const;

	String& operator=(const char*);
	String& operator=(const String&);

	String& operator+=(const char*);
	String& operator+=(const String&);
	
	char& operator[](const int) const;

	int size(){return _size;}
	char* c_str(){return _string;};

private:
	int		_size;
	char*	_string;;	
};

bool 
String::operator==(char const *s) const
{
	if(_size != strlen(s))
		return false;
	return strcmp(_string, s) ? false : true;// non-zero : 0
}
bool 
String::operator==(String const &rhs) const
{
	if(_size != rhs._size)
		return false;
	return strcmp(_string, rhs._string) ? false : true;// non-zero : 0
}
