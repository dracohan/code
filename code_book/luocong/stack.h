///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   stack.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/28 11:29:13
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __STACK_H__
#define __STACK_H__

#include "slist.h"

template <class T>
class CStack : public CSList<T>
{
public:
	
	using CSList<T>::IsEmpty;
	using CSList<T>::GetTail;
	using CSList<T>::RemoveTail;
	
public:
	int push(T data);
	int pop(T* data = NULL);
	int top(T* data) const;
};

template <class T>
inline int CStack<T>::push(T data)
{
	return AddTail(data);
}

template <class T>
inline int CStack<T>::pop(T* data)
{
	if(IsEmpty())
		return 0;
	
	if(data)
		top(data);
	
	RemoveTail();
	return 1;
}

template <class T>
inline int CStack<T>::top(T* data) const
{
	ASSERT(data);
	
	if(IsEmpty())
		return 0;
	
	*data = GetTail();
	
	return 1;
}

#endif
