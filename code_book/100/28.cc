#include <iostream>
using namespace std;

int calc(int num) {
	int count;
	while(num){
		count++;
		num = num & (num-1);
	}
	return count;
}

int main() {
	cout << "input n: " << endl;
	int n;
	cin >> n;
	int count = calc(n);
	cout << "The num of 1 in " << n << " is: " << count << endl;
	return 0;
}
