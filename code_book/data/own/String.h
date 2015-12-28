#include <iostream>

using namespace std;

class String;


class String {
	friend istream& operator>>( istream&, String& );
	friend ostream& operator<<( ostream&, String& );
public:
	//String str1;
	//String str2("abcd");
	//String str3(str2);
	String();
	String(const char*);
	String(const String&);

	~String();

	bool operator==(const char*) const;
	bool operator==(const String&) const;
	bool operator!=(const String&) const;

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

