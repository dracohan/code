/*
 * Purpose: 
 * Date: 
 * Page: 
 */
// to include String 
// declaration
#include "3.15_p107_string.h"

// to include strcmp
// in the C standard library
#include <cstring>
#include <iostream>
#include <cassert>
#include <iomanip>


using namespace std;

bool
String::operator==
( const String &rhs ) const {
    if ( _size != rhs._size ) 
        return false;
    else
        return strcmp( _string, rhs._string) ? false : true;
}

bool
String::operator==( const char *c ) const {
    return strcmp( _string, c ) ? false : true;
}


String::String() {
    _size = 0;
    _string = 0;
}


String::String( const String &rhs ) {
    _size = rhs._size;
    if ( !rhs._string ) {
        _string = 0; }
    else {
        _string = new char[_size + 1];
        strcpy( _string, rhs._string );
    }
}


String::String( const char *s ) {
    if ( !s ) {
        _size = 0; _string = 0; }
    else {
        _size = strlen( s );
        _string = new char[_size + 1];
        strcpy( _string, s );
    }
}


String::~String() {
    delete [] _string;
}

String&
String::operator=
( const String &rhs ) {
    if ( this != &rhs ) {
        _size = rhs._size;
        delete [] _string;
        if ( !rhs._string )
            _string = 0;
        else {
            _string = new char[_size + 1];
            strcpy( _string, rhs._string );
        }
    }
    else
        return *this;
}

String&
String::operator=
( const char *c ) {
    if ( !c ) {
        _size = 0; 
        delete [] _string;
        _string = 0;
    }
    else {
        //cout << "operator= invoked for char: " << *c << endl;
        _size = strlen( c );
        delete [] _string;
        _string = new char[_size + 1];
        strcpy( _string, c );
    }    
}

char&
String::operator[](const int index) {
    assert( index >= 0 && index < _size);
    return _string[ index ];
}

istream&
operator>>( istream& io, String &s) {
    const int limit_string_size =   4096;
    char inBuf[ limit_string_size ];

    io >> setw( limit_string_size ) >> inBuf; 
    s = inBuf; //String::operator=( const char* )

    return io;
}

ostream& 
operator<<( ostream& os, String &s) {
    os << s.c_str();
}

