///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   clist.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/25 10:05:10
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __CIRC_LIST_H__
#define __CIRC_LIST_H__

#include "slist.h"

	
template <typename T>
class CCList : public CSList<T>
{
public:
	using CSList<T>::m_nCount;
	using CSList<T>::m_pNodeHead;

protected:
	CNode<T> *m_pNodeCurr;

public:
	CCList();

public:
	T& GetNext();
	void RemoveAt(const int pos);
	int GetCurrentIndex() const;
};

template <class T>
inline CCList<T>::CCList()
{
}

template <typename T>
inline T& CCList<T>::GetNext()
{
	ASSERT(0 != m_nCount);
	
	if((NULL == m_pNodeCurr) || (NULL == m_pNodeCurr->next))
		m_pNodeCurr = m_pNodeHead;
	else
		m_pNodeCurr = m_pNodeCurr->next;

	return m_pNodeCurr->data;
}

template <typename T>
inline int CCList<T>::GetCurrentIndex() const
{
	ASSERT(0 != m_nCount);
	
	int i;
	CNode<T> *pTmpNode = m_pNodeHead;
	
	for(i = 1; i <= m_nCount; ++i)
	{
		if(pTmpNode == m_pNodeCurr)
			return i;
		else
			pTmpNode = pTmpNode->next;
	}
	
	return 0;
}

template <typename T>
inline void CCList<T>::RemoveAt(const int pos)
{
	ASSERT(1 <= pos && pos <= m_nCount);
	
	int i;
	CNode<T> *pTmpNode1;
	CNode<T> *pTmpNode2;
	
	pTmpNode1 = m_pNodeHead;
	
	//head node?
	if(1 == pos)
	{
		if(m_pNodeCurr == m_pNodeHead)
			m_pNodeCurr = NULL;
		m_pNodeHead = m_pNodeHead->next;
		goto Exit1;
	}

	for(i = 1; i < pos; ++i)
	{
		pTmpNode2 = pTmpNode1;
		pTmpNode1 = pTmpNode1->next;
	}
	pTmpNode2->next = pTmpNode1->next;
	
	m_pNodeCurr = pTmpNode2;
		
Exit1:
	delete pTmpNode1;
	--m_nCount;
}

/*
template <typename T>
inline CCList<T>::~CCList() : m_pNodeCurr(NULL)
{
}
*/

#endif

