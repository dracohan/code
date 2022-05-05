//DeepCopy.cpp 
#include <iostream>
using namespace std;

template<class object>
class ObjectCell {
	public:
		explicit ObjectCell(object initValue = object());
		ObjectCell(const ObjectCell &rhs);
		~ObjectCell();
		
		const ObjectCell& operator=(const ObjectCell &rhs);
		
		object read();
		void write(object x);
	private:
		object* storeValue;
};

template<class object>
ObjectCell<object>::ObjectCell(object initValue) {
	storeValue = new object(initValue);
}

template<class object>
ObjectCell<object>::ObjectCell(const ObjectCell &rhs) {
	storeValue = new object(*rhs.storeValue);
}

template<class object>
ObjectCell<object>::~ObjectCell() {
	delete storeValue;
}

template<class object>
const ObjectCell<object>& ObjectCell<object>::operator=(const ObjectCell &rhs) {
	if(this != &rhs)
		*storeValue = *rhs.storeValue;
	return *this;
}

template<class object>
object ObjectCell<object>::read() {
	return *storeValue;
}

template<class object>
void ObjectCell<object>::write(object x) {
	*storeValue = x;
}

int main() {
	ObjectCell<int> icell1;
	ObjectCell<int> icell2(2);
	ObjectCell<int> icell3(icell2);

	cout << icell1.read() << endl;
	cout << icell2.read() << endl;
	cout << icell3.read() << endl;

	icell3.write(5);
	cout << icell3.read() << endl;

	ObjectCell<int> icell4;
	ObjectCell<int> icell5;
	icell5 = icell4 = icell3;
	cout << icell4.read() << endl;
	cout << icell5.read() << endl;
}