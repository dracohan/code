//template
#include <iostream>

using namespace std;

//inline definition
template <class T>
class Array {
  enum { size = 100 };
  T A[size];
public:
  T& operator[](int index){ 
    if(index > size)
      cout << "Index out of range" << endl;
    else
      return A[index];
  }
};

int main() {
  Array<int> iarray;
  Array<double> darray;

  for(int i=1; i<=20; i++) {
    iarray[i] = i*i;
    darray[i] = i*2.0;
  }

  for(int i=1; i<=20; i++) {
    cout << "iarray[" << i << "] is: " << iarray[i] << endl;
    cout << "darray[" << i << "] is: " << darray[i] << endl;
  } 

  return 0;
}

//non-inline definition
template <class T>
class Array {
  ...
  T& operator[] (int index);
};
template<class T>
T& Array<T>::operator[](int index) {
  ...
}

//not only class T could be used
template <class T, int size = 100> 
class Array {
 T A [size];
 Array<T, size>* np;
 ...
};

//max function
template <class T>
inline const T& max(const T& a, const T& b)
{
  return (a>b) ? a : b;
}

//omit type, use QueueItem instead of QueueItem<type>
template <class type>
class QueueItem {
public:
  QueueItem(const Type& );
private:
  Type Item;
  QueueItem *next;
};

//typename usage
template <class T>
class MyClass {
	typename T::subtype * ptr;
	...
};
