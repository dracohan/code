///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   dlist.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/25 13:08:05
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__

#include <assert.h>
//#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_NEW new (_NORMAL_BLOck, THIS_FILE, __LINE__)
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef _DEBUG
#ifndef ASSERT
#define ASSERT assert
#endif
#else //not _DEBUG
#ifndef ASSERT
#define ASSERT
#endif
#endif //_DEBUG

template <typename T>
class CNode
{
public:
	T data;
	CNode<T> *prior;
	CNode<T> *next;
	CNode() : data(T()),prior(NULL),next(NULL){}
	CNode(const T &initdata) : data(initdata),prior(NULL),next(NULL){}
};

template <typename T>
class CDList
{
protected:
	int m_nCount;
	CNode<T> *m_pNodeHead;
	CNode<T> *m_pNodeTail;
	
public:
	CDList();
	CDList(const T &initdata);
	~CDList();
	
public:
	int IsEmpty() const;
	int GetCount() const;
	int InsertBefore(const int pos, const T data);
	int InsertAfter(const int pos, const T data);
	int AddHead(const T data);
	int AddTail(const T data);
	void RemoveAt(const int pos);
	void RemoveHead();
	void RemoveTail();
	void RemoveAll();
	T& GetTail();
	T GetTail() const;
	T& GetHead();
	T GetHead() const;
	T& GetAt(const int pos);
	T GetAt(const int pos) const;
	void SetAt(const int pos, T data);
	int Find(const T data) const;
	T& GetPrev(int &pos);
	T& GetNext(int &pos);
};

template <typename T>
inline CDList<T>::CDList() : m_nCount(0),m_pNodeHead(NULL),m_pNodeTail(NULL)
{
}

template <typename T>
inline CDList<T>::CDList(const T &initdata)
			: m_nCount(0),m_pNodeHead(NULL),m_pNodeTail(NULL)
{
	AddHead(initdata);
}

template <typename T>
inline CDList<T>::~CDList()
{
	RemoveAll();
}

template <typename T>
inline T& CDList<T>::GetNext(int &pos)
{
	ASSERT(0 != m_nCount);
	ASSERT(1 <= pos && pos <= m_nCount);
	
	int i;
	CNode<T> *pTmpNode = m_pNodeHead;
	
	for(i = 1; i<pos; ++i)
	{
		pTmpNode = pTmpNode->next;
	}
	
	++pos;
	
	return pTmpNode->data;
}

template <typename T>
inline T& CDList<T>::GetPrev(int &pos)
{
	ASSERT(0 != m_nCount);
	ASSERT(1 <= pos && pos <= m_nCount);
	
	int i;
	CNode<T> *pTmpNode = m_pNodeHead;
	
	for(i = 1; i < pos; ++i)
	{
		pTmpNode = pTmpNode->next;
	}
	
	--pos;
	
	return pTmpNode->data;
}

template <typename T>
inline int CDList<T>::InsertBefore(const int pos, const T data)
{
	int i;
	int nRetPos;
	CNode<T> *pTmpNode;
	CNode<T> *pNewNode;
	
	pNewNode = new CNode<T>;
	if(NULL == pNewNode)
	{
		nRetPos = 0;
		goto Exit0;
	}

	pNewNode->data = data;
	
	//if the list is empty, replace the head node with the new node
	if(NULL == m_pNodeHead)
	{
		pNewNode->prior = NULL;
		pNewNode->next = NULL;
		m_pNodeHead = pNewNode;
		m_pNodeTail = pNewNode;
		nRetPos = 1;
		goto Exit1;
	}
	
	//is po range valid?
	ASSERT(1 <= pos && pos <= m_nCount);
	
	//insert before head node
	if(1 == pos)
	{
		pNewNode->prior = NULL;
		pNewNode->next = m_pNodeHead;
		m_pNodeHead->prior = pNewNode;
		m_pNodeHead = pNewNode;
		nRetPos = 1;
		goto Exit1;
	}
	
	//if the list is not empty and is not insert before head node
	//seek to the pos of the list and insert the new node before it
	pTmpNode = m_pNodeHead;
	for(i=1; i<pos; ++i)
	{
		pTmpNode=pTmpNode->next;
	}
	pNewNode->next = pTmpNode;
	pNewNode->prior = pTmpNode->prior;
	
	pTmpNode->prior->next= pNewNode;
	pTmpNode->prior = pNewNode;
	
	//if tail node, must update m_pNodeTail;
	if(NULL == pNewNode->next)
	{
		m_pNodeTail = pNewNode;
	}
	
	nRetPos = pos;
Exit1:
	++m_nCount;	
Exit0:
	return nRetPos;
}

template <typename T>
inline int CDList<T>::InsertAfter(const int pos, const T data)
{
	int i;
	int nRetPos;
	CNode<T> *pNewNode;
	CNode<T> *pTmpNode;
	
	pNewNode = new CNode<T>;
	if(NULL == pNewNode)
	{
		nRetPos = 0;
		goto Exit0;
	}
	
	pNewNode->data = data;
	
	//if the list is empty, replace the head node with the new node
	if(NULL == m_pNodeHead)
	{
		pNewNode->prior = NULL;
		pNewNode->next = NULL;
		m_pNodeHead = pNewNode;
		m_pNodeTail = pNewNode;
		nRetPos = 1;
		goto Exit1;
	}
	
	//is pos range valid?
	ASSERT(1 <= pos && pos <= m_nCount);;

	//if the list is not empty
	//seek to the pos of the list and insert the new node after it.
	pTmpNode = m_pNodeHead;
	for(i=1; i<pos; ++i)
	{
		pTmpNode = pTmpNode->next;
	}
	
	pNewNode->prior = pTmpNode;
	pNewNode->next = pTmpNode->next;
	
	//if NewNode position is m_pNodeTail, update m_pNodeTail
	if(pTmpNode->next == m_pNodeTail)
	{
		m_pNodeTail->prior = pNewNode;
	}
	
	pTmpNode->next = pNewNode;
	
	//if tail node, must update m_pNodeTail
	if(NULL == pNewNode->next)
	{
		m_pNodeTail = pNewNode;
	}
	nRetPos = pos + 1;
	
Exit1:
	++m_nCount;
Exit0:
	return nRetPos;
}

template <typename T>
inline T& CDList<T>::GetAt(const int pos)
{
	ASSERT(1 <= pos && pos <= m_nCount);
	
	int i;
	CNode<T> *pTmpNode = m_pNodeHead;
	
	for(i = 1; i < pos; ++i)
	{
		pTmpNode = pTmpNode->next;
	}
	
	return pTmpNode->data;
}

template <typename T>
inline int CDList<T>::AddHead(const T data)
{
	return InsertBefore(1, data);
}

template <typename T>
inline int CDList<T>::AddTail(const T data)
{
	return InsertAfter(GetCount(), data);
}

template <typename T>
inline int CDList<T>::IsEmpty() const
{
	return 0 == m_nCount;
}

template <typename T>
inline int CDList<T>::GetCount() const
{
	return m_nCount;
}
template <typename T>
inline T& CDList<T>::GetTail()
{
	ASSERT(0 != m_nCount);
	return m_pNodeTail->data;
}
template <typename T>
inline T& CDList<T>::GetHead()
{
	ASSERT(0 != m_nCount);
	return m_pNodeHead->data;
}

template <typename T>
inline void CDList<T>::RemoveAt(const int pos)
{
	ASSERT(1 <= pos && pos <= m_nCount);
	
	int i;
	CNode<T> *pTmpNode = m_pNodeHead;
	
	//head node?
	if(1 == pos)
	{
		m_pNodeHead = m_pNodeHead->next;
		goto Exit1;
	}
	
	for(i = 1; i < pos; ++i)
	{
		pTmpNode = pTmpNode->next;
	}
	pTmpNode->prior->next = pTmpNode->next;
		
Exit1:
	delete pTmpNode;
	--m_nCount;
	if(0 == m_nCount)
	{
		m_pNodeTail = NULL;
	}
}

template <typename T>
inline void CDList<T>::RemoveHead()
{
	ASSERT(0 != m_nCount);
	RemoveAt(1);
}

template <typename T>
inline void CDList<T>::RemoveTail()
{
	ASSERT(0 != m_nCount);
	RemoveAt(GetCount());
}

template <typename T>
inline void CDList<T>::RemoveAll()
{
	int i;
	int nCount;
	CNode<T> *pTmpNode;
	
	nCount = m_nCount;
	for(i = 0; i < nCount; ++i)
	{
		pTmpNode = m_pNodeHead->next;
		delete m_pNodeHead;
		m_pNodeHead = pTmpNode;
	}
	
	m_nCount = 0;
}

template <typename T>
inline void CDList<T>::SetAt(const int pos, T data)
{
	ASSERT(1 <= pos && pos <= m_nCount);
	int i;
	CNode<T> *pTmpNode = m_pNodeHead;
	
	for(i = 0; i < m_nCount; ++i)
	{
		pTmpNode = pTmpNode->next;
	}
	
	pTmpNode->data = data;
}

template <typename T>
inline int CDList<T>::Find(const T data) const
{
	int i;
	int nCount;
	CNode<T> *pTmpNode = m_pNodeHead;
	
	for(i = 0; i < m_nCount; ++i)
	{
		if(pTmpNode->data == data)
			return i + 1;
		pTmpNode = pTmpNode->next;
	}
	
	return 0;
}

#endif // __DOUBLE_LIST_H__
