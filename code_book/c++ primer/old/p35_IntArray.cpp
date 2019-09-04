#include "p35_IntArray.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

IntArray::
IntArray( int size ) { init(size, 0 ); }

IntArray::
IntArray( int *array, int array_size ) {
	init(array_size,  array);
}

IntArray::
IntArray( const IntArray &rhs ) {
	init( rhs._size, rhs._ia );
}

void
IntArray::
init( int sz, int *array ) {
	_size = sz;
	_ia = new int[ _size ];

	for(int ix = 0; ix < _size; ++ix)
		if( !array )
			_ia[ ix ] = 0;	
		else
			_ia[ ix ] = array[ ix ];
}	

bool
IntArray::
operator==( const IntArray &rhs ) const {
	if( _size != rhs._size )
		return false;
	return (_ia == rhs._ia ) ? false : true; 
}

inline bool 
IntArray::
operator!=( const IntArray &rhs ) const {
	return true;
}
