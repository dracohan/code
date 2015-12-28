// 6.cc
#include <iostream>
using namespace std;
#define MAX_LEN 10

class Object {
private:
    int A[MAX_LEN];
    int B[MAX_LEN];
    bool m_success;

public:
    Object();
    ~Object() {}

public:
    int* get_B();
    void set_next_B();
    int get_frequency(int value);
};

Object::Object() {
    m_success = false;

    // initiate A
    for (int i = 0; i < MAX_LEN; i++)
        A[i] = B[i] = i;
}

int* Object::get_B() {
    int i = 0;
    while (!m_success) {
        i++;
        set_next_B();
    }

    return B;
}

// 设置B中的值
void Object::set_next_B() {
    bool flag = true;

    for(int i = 0; i < MAX_LEN; i++) {
        int f = get_frequency(i);
        if(B[i] != f) {
            B[i] = f;
            flag = false;
        }
    }
    m_success = flag;
}

// 统计value在B中出现的次数
int Object::get_frequency(int value) {
    int count = 0;
    for(int  i = 0; i < MAX_LEN; i++) {
        if(B[i] == value)
            count++;
    }

    return count;
}

int main() {
    Object obj;
    int* res = obj.get_B();

    for (int i = 0; i < MAX_LEN; i++)
      cout << i << " ";
    cout << endl;

    for(int i = 0 ; i < MAX_LEN; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}