///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   slist.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/14 14:41:40
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__

#include <assert.h>
//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>

#ifdef _DEBUG
#define _DEBUG_NEW new (_NORMAL_BLOCK, THIS_FILE, __LINE__)
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
class CNode {
public:
    T data;
    CNode<T> *next;
    CNode() : data(T()), next(NULL) {};
    CNode(const T &initdata) : data(initdata), next(NULL) {};
    CNode(const T &initdata, CNode<T> *p) : data(initdata), next(p) {};
};

template <typename T>
class CSList {
protected:
    int m_nCount;
    CNode<T> *m_pNodeHead;
    
public:
    CSList();
    CSList(const T &initdata);
    ~CSList();

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
}; 

template <typename T>
CSList<T>::CSList() : m_nCount(0), m_pNodeHead(NULL)
{
}

template <typename T>
CSList<T>::CSList(const T &initdata) : m_nCount(0), m_pNodeHead(NULL)
{
    AddHead(initdata);
}

template <typename T>
inline CSList<T>::~CSList()
{
    RemoveAll();
}

template <typename T>
inline int CSList<T>::GetCount() const
{
    return m_nCount;
}

template <typename T>
inline int CSList<T>::IsEmpty() const
{
    return 0 == m_nCount;
}

template <typename T>
inline int CSList<T>::AddHead(const T data)
{
    CNode<T> *pNewNode;
    pNewNode = new CNode<T>;
    
    if(NULL == pNewNode)
        return 0;
    
    pNewNode->data = data;
    pNewNode->next = m_pNodeHead;
    
    m_pNodeHead = pNewNode;
    ++m_nCount;
    
    return 1;
}

template <typename T>
inline int CSList<T>::AddTail(const T data)
{
    InsertAfter(GetCount(), data);    
}

//if success, return the postion of the new node
//if fail, return 0 
template <typename T>
inline int CSList<T>::InsertBefore(const int pos, const T data)
{
    int i;
    int nResPos;
    CNode<T> *pTmpNode1;
    CNode<T> *pTmpNode2;
    CNode<T> *pNewNode;
    
    pNewNode = new CNode<T>; 
    if( NULL == pNewNode )
    {
        nResPos = 0;
        goto Exit0;
    }
    
    pNewNode->data = data;
    
    //if the list is empty, replace head node with new node
    if(NULL = m_pNodeHead)
    {
        pNewNode->next = NULL;
        m_pNodeHead = pNewNode;
        nResPos = 1;
        goto Exit1;
    }
    
    //assert pos is valid
    ASSERT(1 <= pos && pos <= m_nCount);
    
    //insert before head node ? 
    if(1 == pos)
    {
        pNewNode->next = m_pNodeHead;
        m_pNodeHead = pNewNode;
        nResPos = 1;
        goto Exit1;
    }
    
    //if the list is not empty and is not inserted before head node
    //seek to the pos of the list and insert the new node before it
    pTmpNode1 = m_pNodeHead;
    for(i = 1; i < pos; i++)
    {
        pTmpNode2 = pTmpNode1;
        pTmpNode1 = pTmpNode1->next;
    }
    pNewNode->next = pTmpNode1;
    pTmpNode2->next = pNewNode; 
    nResPos = pos;
    
Exit1:
    ++m_nCount;
Exit0:
    return nResPos;        
}
//if success, return the postion of the new node
//if fail, return 0
template <typename T>
inline int CSList<T>::InsertAfter(const int pos, const T data)
{
	int nResPos;
	int i;
	CNode<T> *pNewNode;
	CNode<T> *pTmpNode;
	
	pNewNode = new CNode<T>;
	if(NULL == pNewNode)
	{
		nResPos = 0;
		goto Exit0;
	}
	
	pNewNode->data = data;
	
    //empty list?
    if(NULL == m_pNodeHead)
	{
		pNewNode->next = NULL;
		m_pNodeHead = pNewNode;
		nResPos = 1;
		goto Exit1;
	}
	
    //check range
    ASSERT(1 <= pos && pos <= m_nCount);
    
    //seek pos
    pTmpNode= m_pNodeHead;
    for(i = 1; i < pos; i++)
    {
    	pTmpNode = pTmpNode->next;
    }
    pNewNode->next = pTmpNode->next;
    pTmpNode->next = pNewNode;
    nResPos = pos + 1;
    
Exit1:
	++m_nCount;
Exit0:
	return nResPos;
}

template <typename T>
inline void CSList<T>::RemoveAt(const int pos)
{
	//check range
	ASSERT(1 <= pos && pos <= m_nCount);
	
	int i;
	CNode<T> *pTmpNode1;
	CNode<T> *pTmpNode2;
	
	//see the position
	pTmpNode1 = m_pNodeHead;
	
	if(1 == pos)
	{
		m_pNodeHead = m_pNodeHead->next;
		goto Exit1;
	}
	
	for(i = 1; i < pos; i++)
	{
		pTmpNode2 = pTmpNode1;
		pTmpNode1 = pTmpNode1->next;
	}
	pTmpNode2->next = pTmpNode1->next;
	
Exit1:
	delete pTmpNode1;
	--m_nCount;
}

template <typename T>
inline void CSList<T>::RemoveHead()
{
	ASSERT(0 != m_nCount);
	RemoveAt(1);
}

template <typename T>
inline void CSList<T>::RemoveTail()
{
	ASSERT(0 != m_nCount);
	RemoveAt(m_nCount);
}

template <typename T>
inline void CSList<T>::RemoveAll()
{
	int i;
	int nCount; 
	CNode<T> *pTmpNode;
	
	nCount = m_nCount;
	for(i = 1; i < nCount; i++)
	{
		pTmpNode = m_pNodeHead->next;
		delete m_pNodeHead;
		m_pNodeHead = pTmpNode	;
	}
	m_nCount = 0;
}

template <typename T>
inline T& CSList<T>::GetTail()
{
	ASSERT(0 != m_nCount);
	
	int i;
	CNode<T> *pTmpNode = m_pNodeHead;
	
	pTmpNode = m_pNodeHead;
	for(i = 1; i < m_nCount; i++)
		pTmpNode = pTmpNode->next;
	
	return pTmpNode->data; 
}
	
template <typename T>
inline T CSList<T>::GetTail() const
{
	ASSERT(0 != m_nCount);
	
	int i;
	CNode<T> *pTmpNode = m_pNodeHead;
	
	pTmpNode = m_pNodeHead;
	for(i = 1; i < m_nCount; i++)
		pTmpNode = pTmpNode->next;
	
	return pTmpNode->data;
}

template <typename T>
inline T& CSList<T>::GetHead()
{
	ASSERT(0 != m_nCount);
	return m_pNodeHead->data;
}

template <typename T>
inline T CSList<T>::GetHead() const
{
	ASSERT(0 != m_nCount);
	return m_pNodeHead->data;
}

template <typename T>
inline T& CSList<T>::GetAt(const int pos)
{
	ASSERT(1 <= pos && pos <= m_nCount);
	
	int i;
	CNode<T> *pTmpNode;
	
	pTmpNode =  m_pNodeHead;	
	for(i = 1; i < pos; i++)
		pTmpNode = pTmpNode->next;
	
	return pTmpNode->data;
}
	
template <typename T>
inline T CSList<T>::GetAt(const int pos) const
{
	ASSERT(1 <= pos && pos <= m_nCount);
	
	int i;
	CNode<T> *pTmpNode;
	
	pTmpNode =  m_pNodeHead;	
	for(i = 1; i < pos; i++)
		pTmpNode = pTmpNode->next;
	
	return pTmpNode->data;
}

template <typename T>
inline void CSList<T>::SetAt(const int pos, T data)
{
	ASSERT(1 <= pos && pos <= m_nCount);
	
	int i;
	CNode<T> pTmpNode = m_pNodeHead;
	
	for(i = 1; i < pos; i++)
		pTmpNode = pTmpNode->next;
	
	pTmpNode->data = data;
}

template <typename T>
inline int CSList<T>::Find(const T data) const
{
	ASSERT(0 != m_nCount);
	
	int i;
	CNode<T> *pTmpNode = m_pNodeHead;
	
	for(i = 1; i < m_nCount; i++)
	{
		if(pTmpNode->data == data)
			return i;
		
		pTmpNode = pTmpNode->next;
	}
	
	return 0;
}

#endif
    