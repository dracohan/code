#include "p35_IntArrayRC.h"
#include <iostream>
#include <assert>
#include <cassert>
#include <string>

using namespace std;

inline int&
IntArrayRC::
operator[]( int index ) {
	check_range( index );
	return _ia[ index ];
}

inline void 
IntArrayRC::
check_range( int index ) {
	assert( index >= 0 && index < _size);
}

inline 
IntArrayRC::
IntArrayRC( int sz ) : IntArray( sz ) {}
 
	
