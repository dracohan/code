// 29.cc
#include <iostream>
#include <stack>
using namespace std;

bool is_valid_pop(const int* a, const int* b, int size) {
	if (!a || !b || !size)
		return false;

	stack<int> s;
	int i = 0, j = 0;
	while (i < size && j < size) {
		// 栈顶元素不是当前出栈元素
		while(s.empty() || s.top() != b[j]) {
			s.push(a[i]);
			i++;
			if (i == size)
				break;
		}
		if (b[j] != s.top())
			return false;

		s.pop();
		j++;
	}

	if (s.empty() && j == size)
		return true;
	else
		return false;
}

int main() {
	int a[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
	int b[] = {3, 2, 4, 1, 5, 9, 10, 7, 8};
	bool flag = is_valid_pop(a, b, sizeof(a) / sizeof(int));
	cout << flag << endl;
	return 0;
}