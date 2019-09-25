#include <iostream>

using namespace std;

void gcd(int &a) {
    a = 2;
}

int main() {
    cout << "hello" << endl;
    int i = 1;
    gcd(i);
    cout << "i: " << i << endl;
}