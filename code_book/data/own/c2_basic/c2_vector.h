///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   c2_vector.h
//  Author      :   Jimmy Han
//  Date        :   N.A 			    v1    
//              :   2014/07/13 09:30    v2    
//
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
 
template <class object>
class Vector {
public:
	explicit Vector(int initsize = 0)
		: _size(initsize), _capacity(initsize + SPARE_CAPACITY)
			{_object = new object[_capacity];}

	Vector(const Vector &rhs) : _object(NULL) 
		{ operator=(rhs);}
		
	~Vector()
		{delete [] _object;}
		
	const Vector& operator=(const Vector &rhs)
	{
		if(this != &rhs)
			{
				delete [] _object;
				_size = rhs._size;
				_capacity = rhs._capacity;
				
				_object = new object[_capacity];
				for(int k = 0; k < _size; k++)
					_object[k] = rhs._object[k];	
			}
			return *this;
	}
	
	void resize(int newSize)
	{
		if(newSize > _capacity)
			reserve(newSize * 2 + 1);
		_size = newSize;
	}
	
	void reserve(int newCapacity)
	{
		if(newCapacity < _size)
			return;
		
		object *oldobject = _object;
		_object = new object[newCapacity];
		for (int n=0; n<_size; n++)
			_object[n] = oldobject[n];
		delete [] oldobject;
		_capacity = newCapacity;
	}
	
	object& operator[](const int index)
	{
		assert(index >= 0 && index < _size);
		return _object[index];
	}
	
	const object& operator[](const int index) const
	{
		assert(index >= 0 && index < _size);
		return _object[index];
	}
	
	bool empty() const 
	{return _size == 0;}
	
	int size() const 
	{return _size;}
	
	int capacity() const 
	{return _capacity;}
	
	void push_back(const object &x)
	{
		if(_size == _capacity)
			reserve(2*_capacity + 1);
		_object[_size++] = x;
	}
	
	void pop_back()
		{_size--;}
	
	const object& back() const 
		{ return _object[_size - 1];}
	
	typedef object* iterator ;
	typedef const object* const_iterator;
	
	iterator begin()
	{return &_object[0];}
	
	iterator end()
	{return	 &_object[_size];}

	const_iterator begin() const
	{return &_object[0];}
	
	const_iterator end() const
	{return &_object[_size];}	

	enum{ SPARE_CAPACITY = 3};	
private:
	int _size;
	int _capacity;
	object *_object;	
};

