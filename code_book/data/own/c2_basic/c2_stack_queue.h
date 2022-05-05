#include "c2_list.h"

template <typename object>
class Stack{
public:
	bool isEmpty() const
	{return _list.empty();}

	const object& top() const
	{_list.front();}

	void push(const object& x)
	{_list.push_front(x);}

	object pop()
	{object x = _list.front(); _list.pop_front(); return x;}

private:
	List<object> _list;
};

template <typename object>
class Queue{
public:
	bool isEmpty() const
	{return _list.empty();}

	void enqueue(const object& x)
	{_list.push_back(x);}

	object dequeue()
	{object x = _list.front(); _list.pop_front(); return x;}

	const object& getFront(object& x)
	{return _list.front();}
	
private:
	List<object> _list;
};