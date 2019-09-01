#ifndef _INTARRAY_H
#define _INTARRAY_H

class IntArray {
    public:
        explicit IntArray( int size = default_size );
        IntArray( int *array, int array_size);
        IntArray( const IntArray &rhs );
        
        virtual ~IntArray() { delete [] ia; }
        
        bool operator==( const IntArray &rhs) const;
        bool operator!=( const IntArray &rhs) const;

        IntArray& operator=( const IntArray &rhs );

        virtual int operator[]( int index ) { return _ia[index]; }
        virtual int sort();
        virtual int max() const; 
        virtual int min() const;
        virtual int find( int value ) const;

    private:
        static const int default_size = 12;
        void init( int sz, int *array );
        int _size;
        int *_ia;
};

#endif
