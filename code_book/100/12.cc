// 12.cc
#include <iostream>
using namespace std;

class Object {
public:
	Object() {
		++N;
		Sum += N;
	}
	static void reset() { N = 0; Sum = 0; }
	static int get_sum() { return Sum; }

private:
	static int N;
	static int Sum;
};

int Object::N = 0;
int Object::Sum = 0;

int sum(int n) {
	Object::reset();

	Object* a = new Object[n];

	delete []a;
	a = 0;

	return Object::get_sum();
}

int main() {
	int n = 10;
	cout << "The sum is: " << sum(n) << endl;
	return 0;
}