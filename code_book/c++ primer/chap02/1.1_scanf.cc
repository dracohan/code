#include <iostream>

using namespace std;

int main() {
    int i, j, k, t;
    uint64_t m;
    uint32_t n;
    string s = "perfc[1][2][3][4]=5(0x0000000a)";
    sscanf(s.c_str(), "perfc[%d][%d][%d][%d]=%d(0x%x)", &i, &j, &k, &t, &m, &n);
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
    cout << "k: " << k << endl;
    cout << "t: " << t << endl;
    cout << "m: " << m << endl;
    cout << "n: " << n << endl;
}