///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   c2_list.h
//  Author      :   Jimmy Han
//  Date        :   N.A 			    v1    
//              	2014/07/13 12:30    v2   
//				 	2014/07/21 			v3 add operator= & operator+(offset)
//
///////////////////////////////////////////////////////////////////////////////
#ifndef C2_LIST_H
#define C2_LIST_H
#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

template <class object>
class List {
private:
	struct Node{
		object data;
		Node *prev;
		Node *next;
		Node(const object &d = object(), Node *p = NULL, Node *n = NULL)
		: data(d), prev(p), next(n) {}
	};
	
public:
	class const_iterator {
		public:
			const_iterator() : current(NULL)
				 {}

			const object& operator*() const
				{return retrieve();}
			
			const_iterator& operator+(int offset)
			{
				for(int i = 1; i <= offset; i++)
					this->current = this->current->next;
				return *this;
			}

			const_iterator& operator=(const const_iterator& rhs)
			{
				if(current == rhs.current)
				 	return *this;
				Node* oldp = current;
				Node* newp = rhs.current;
				current = newp;
				delete oldp;
				return *this;
			}

			const_iterator& operator++()
			{
				current = current->next;
				return *this;
			}

			const_iterator operator++(int)
			{
				const_iterator old = *this;
				++(*this);
				return old;
			}

			const_iterator& operator--()
			{
				current = current->prev;
				return *this;
			}

			const_iterator operator--(int)
			{
				const_iterator old = *this;
				--(*this);
				return old;
			}
			
			bool operator==(const const_iterator &rhs) const
			{return current == rhs.current;}
			
			bool operator!=(const const_iterator &rhs) const
			{return !(*this == rhs);}
			
		protected:
			Node* current;
			object& retrieve() const
				{return current->data;}

			object& retrieve()
				{return current->data;}
			
			//not used by List, but used by iterator, so protected
			const_iterator( Node *p) : current(p) {}
				
			friend class List<object>;
	};
	class iterator : public const_iterator {
		public:
			iterator()
				 {}

			object& operator*()
			{return this->retrieve();}

			object& operator*() const
			{return const_iterator::operator*()	;}

			iterator& operator+(int offset)
			{
				for(int i = 1; i <= offset; i++)
					this->current = this->current->next;
				return *this;
			}

			iterator& operator=(iterator& rhs)
			{
				const_iterator::operator=(rhs);
				return *this;
			}

			//return type changed, so redefine ++
			iterator& operator++()
			{
				this->current = this->current->next;
				return *this;
			}

			const iterator operator++(int)
			{
				iterator old = *this;
				++(*this);
				return old;
			}

			iterator& operator--()
			{
				this->current = this->current->prev;
				return *this;
			}

			const iterator operator--(int)
			{
				iterator old = *this;
				--(*this);
				return old;
			}

		protected:
			iterator(Node* p) : const_iterator(p) {}
		friend class List<object>;
	};
	
	List()
	{init();}

	List(const List &rhs)
	{
		init();
		*this = rhs;
	}

	~List()
	{
		clear();
		delete head; 
		delete tail;
	}

	const List& operator=(const List &rhs)
	{
		if(this == &rhs)
			return *this;
		clear();
		for (const_iterator iter=rhs.begin(); iter!=rhs.end(); ++iter)
			push_back(*iter);
		return *this;
	}
	
	iterator begin()
	{return iterator(head->next); }

	iterator end()
	{return iterator(tail);}

	const_iterator begin() const 
	{return const_iterator(head->next); }

	const_iterator end() const 
	{return const_iterator(tail);}

	int size() const
	{return _size;}

	bool empty() const
	{return size() == 0;}

	void clear()
	{
		while(!empty())
			pop_front();
	}
	object& front()
	{return *begin();}

	const object& front() const
	{return *begin();}

	object& back()
	{return *--end();}

	const object& back() const
	{return *--end();}

	void push_front(const object &x)
	{insert(begin(), x);}

	void push_back(const object &x)
	{insert(end(), x);}

	void pop_front()
	{erase(begin());}

	void pop_back()
	{erase(--end());}

	//insert object value as x before iter
	//return the position of the new inserted object
	iterator insert(iterator iter, const object &x)
	{ 
		//current is private, could be access cus of friend classs
		Node* p = iter.current;
		_size++;
		return iterator(p->prev = p->prev->next = new Node(x, p->prev, p)); 
	}

	//erase the object iter point to
	//return the next object of iter
	iterator erase(iterator iter)
	{
		if (!empty())
		{
			/* code */
			Node* p = iter.current;
			iterator retVal(p->next);
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			--_size;
			return retVal;
		}
		else
		{
			cout << "Empty List!!" << endl;
			return iter;
		}
	}

	iterator erase(iterator start, iterator end)
	{
		for(iterator iter = start; iter != end; )
			iter = erase(iter);
		return end;
	}

	object& getat(const int idx)
	{
		assert(1 <= idx && idx <= _size);
		iterator iter = begin() + idx;
		return iter.retrieve();
	}

private:
	int _size;
	Node *head;
	Node *tail;

	void init()
	{
		//loop list?
		_size = 0;
		head	= new Node;
		tail 		= new Node;
		head->next 	= tail;
		tail->prev		= head;
	}

};

#endif

