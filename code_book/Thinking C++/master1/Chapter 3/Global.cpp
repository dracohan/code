//: C03:Global.cpp
//{L} Global2
// ������������� ���������� ����������
#include <iostream>
using namespace std;

int globe;
void func();
int main() {
	globe = 12;
	cout << globe << endl;
	func();	// ����������� globe
	cout << globe << endl;
} ///:~