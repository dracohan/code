#include "IntCell.h"

IntCell::IntCell(int initialValue) : _storeData(initialValue)
{
    //do everything in default list
}

IntCell::IntCell(const IntCell &rhs) : _storeData(rhs._storeData)
{
	//do everything in default list
}

IntCell& IntCell::operator=( const IntCell &rhs ) 
{
	if( this != &rhs)
		_storeData = rhs._storeData;
	return *this;	
}

int IntCell::ReadData() const
{
    return _storeData;
}

void IntCell::WriteData(int newData)
{
    _storeData = newData;
}

