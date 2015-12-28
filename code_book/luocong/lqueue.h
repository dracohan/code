///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   lqueue.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/28 15:24:49
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

#include "slist.h"
#include <iostream>
using namespace std;

template <class T>
class CLQueue : public CSList<T>
{
	using CSList<T>::GetHead;
	using CSList<T>::GetTail;
	using CSList<T>::RemoveHead;
	
public:
	int EnQueue(const T data);
	T	DeQueue();
	T&	GetFront();
	T	GetFront() const;
	T&	GetRear();
	T	GetRear() const;
};

template <class T>
inline int CLQueue<T>::EnQueue(const T data)
{
	return AddTail(data);
}

template <class T>
inline T CLQueue<T>::DeQueue()
{
	T data = GetHead();
	RemoveHead();
	return data;
}

template <class T>
inline T& CLQueue<T>::GetFront()
{
	return GetHead();
}

template <class T>
inline T CLQueue<T>::GetFront() const
{
	return GetHead();
}

template <class T>
inline T& CLQueue<T>::GetRear()
{
	return GetTail();
}

template <class T>
inline T CLQueue<T>::GetRear() const
{
	return GetTail();
}

#endif //__LIST_QUEUE_H__

	