///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   c2_introduction.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2014/1/2 19:07
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef C2_INTRODUCTION_H
#define	C2_INTRODUCTION_H

template<typename T>
inline const T& max(const T& a, const T& b)	
{
	//if a < b, then use b instead of a
	return a < b ? b : a;
}

//class template
template<typename T>
class MyClass{
	//without typename would be a multiplication of value SubType of type T with ptr
	typename T::SubType* ptr;
};

//function template
template<typename T>
class MyClass{
	private:
		T value;
	public:
		template<T>
		void f(const MyClass<T>& x){
			value = x.value;
		}
};

//ctor template is used to provide implicit conversions
template<typename T>
class MyClass{
private:
	T value;
public:
	template<typename X>
	MyClass(const MyClass<X>& x){
		//copy ctor with implicit type conversion
		//do NOT hide implicit copy ctor
		//MyClass<double> md1;
		//Myclass<double> md2 = md1; //will call implicit copy ctor
		//MyClass<int> md3 = md1; 	//will call template copy ctor
	}
};

//explicit 
template<typename T>
class MyClass
{
public:
	explicit MyClass(T size);
	~MyClass();

	/* data */
};
//MyClass<int> mc(40); //OK
//MyClass<int> mc = 40; //NOK

//static member could be initialized in class
//but still should be defined outside of class
class MyClass{
static const int a = 1024;
};
const MyClass::int a;

//two portable main
int main()
{

}
int main(int argc, char* argv[])
{

}


#endif