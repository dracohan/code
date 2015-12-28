#include <iostream>

using namespace std;

class String;

istream& operator>>( istream&, String& );
ostream& operator<<( ostream&, String& );

class String {
    public:
        //String str1;
        //String str2( "literal" );
        //String str3( str2 );
        String();
        String( const char* );
        String( const String& );

        ~String();
        
        bool operator==( const String& ) const;
        bool operator==( const char* ) const;
        bool operator!=( const String& ) const;

        String& operator=( const String& );
        String& operator=( const char* );
        char& operator[]( const int );

        int size() { return _size; }
        char* c_str() { return _string; }

    private:
        char *_string;
        int _size;
};

