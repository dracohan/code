#ifndef ARRAYRC_H
#define ARRAYRC_H

#include "Array.h"

template <class elemType>
class ArrayRC : public virtual Array<elemType> {
public:
    //JM change: DefaultArraySize to Array<elemType>::DefaultArraySize
    ArrayRC( int sz = Array<elemType>::DefaultArraySize )
            : Array<elemType>( sz ) {}

    ArrayRC( const ArrayRC& r );
    ArrayRC( const elemType *ar, int sz );

    elemType  operator[]( int ix ) const;
    elemType& operator[]( int ix );
};

#endif
