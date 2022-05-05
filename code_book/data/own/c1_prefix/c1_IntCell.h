#ifndef _INTCELL_H
#define _INTCELL_H

class IntCell {
public:
    explicit IntCell( int initalValue = 0 ); 
    IntCell(const IntCell &);

    IntCell& operator=( const IntCell & );
    
    int ReadData( ) const;
    void WriteData( int );

private:
    int _storeData; 
};

#endif
