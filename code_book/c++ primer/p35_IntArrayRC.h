#ifndef _INTARRAYRC_H
#define _INTARRAYRC_H
class IntArrayRC : public IntArray {
    public:
        IntarrayRC( int size = default_size);
        IntArrayRC( int *array, int size);
        IntArrayRC( const IntArray &rhs );
        virtual int& operator[]( int ); 
    private:
        void check_rc( int index );

#endif

