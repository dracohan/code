// http://www.cnblogs.com/dracohan/archive/2009/11/30/1614089.html
#include "effect_item3.h"

int main() {
    B b1;
    b1.show();

    B b11(1, "abc");
    cout << b11[0] << endl;

    const B b2(0);
    b2.show();

    const B b22(2, "def");
    cout << b22[1] << endl;
}

