#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    //difference 1: 指向是否可以更改
    //数组内容可变，但是不可以++
    char d1a[] = "hello";
    d1a[2] = 'L';
    //d1a++;
    cout << d1a << endl;
    //指针指向内容可变，也可以++
    char* d1p = "world";
    //d1p[2] = 'R';
    cout << " " << d1p << endl;
    //output the address of point to char
    cout << "the address of d1p is: " 
        << static_cast<void*>(d1p) << endl;
    d1p++;
    cout << "after ++, the address of d1p is: " 
        << static_cast<void*>(d1p) << endl;

    //difference 2: copy and compare
    //ARRAY, 不能使用赋值或者比较
    char a[] = "hello";
    char b[10];
    strcpy(b, a); //can't use b = a;
    //POINTER, valid
    char* pa = "world";
    char* pb;
    pb = pa;

    //difference 3: sizeof
    cout << "the size of a is: " << sizeof(a) << endl;
    cout << "the size of b is: " << sizeof(pa) << endl;
        
}