#include <memory>
#include <map>
#include <iostream>
#include <algorithm>

struct A {
	A(int n) : a(n) {};
	int a;
};

std::unique_ptr<int> create_ptr(A* aa) {
    auto a =  std::make_unique<int>(aa->a);
	auto*ptr = a.get();
	return a;
} // ptr goes out of scope here and the int object it owns is not deleted because it is moved into the map

int main() {
    std::map<int, std::unique_ptr<int>> my_map;
	A* a = new A(34);
	//for (int i = 0; i < 10; i++) {
    my_map.insert(std::make_pair(1, std::move(create_ptr(a))));
//	}
	delete a;
	auto print = [](std::pair<const int, std::unique_ptr<int> >& n){std::cout << " " << *n.second;};
	std::cout << "size: " << my_map.size() << std::endl;
	for_each(my_map.begin(), my_map.end(), print);

	int* ptr = new int(42);
	std::unique_ptr<int> uptr = std::make_unique<int>(*ptr);
	delete ptr; // UB: ptr is deleted before uptr goes out of scope
	std::cout << "val:" << *uptr << std::endl;
    return 0;
} // the int object is deleted when the map goes out of scope

