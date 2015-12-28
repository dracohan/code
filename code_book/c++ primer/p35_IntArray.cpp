#include "p35_IntArray.h"
#include <iostream>
#include <string>

using namespace std;

intline
IntArray::
IntArray( int size ) { init( 0, size ); }

inline
IntArray::
IntArray( int *array, int array_size ) {
	init( array, array_size);
}

inline
IntArray::
IntArray( const IntArray &rhs ) {
	init( rhs._ia, rhs._size );
}


inline
IntArray::
init( int *array, int sz ) {
	_size = sz;
	_ia = new int[ _size ];

	for(int ix = 0; ix < _size; ++ix)
		if( !array )
			_ia[ ix ] = 0;	
		
		else
			_ia[ ix ] = array[ ix ];
}	

inline bool
IntArray::
operator==( const IntArray &rhs ) const {
	if( _size != rhs._size )
		return false;
	return strcmp( _ia, rhs._ia ) ? false : true; 
}

inline bool 
IntArray::
operator!=( const IntArray &rhs ) const {
	return !

