#include<iostream>
#include<typeinfo>
using namespace std;

class Base
{
public:
    virtual void funcA() { cout << "Base" << endl; }
};

class Derived : public Base
{
public:
    virtual void funcB() { cout << "Derived" << endl; }
};

void funcC(Base* p)
{
    Derived* dp = dynamic_cast<Derived*>(p);
    if (dp != NULL) {
        dp->funcB();
    }
    else {
        p->funcA();
    }
};

void funcD(Base* p)
{
    Derived* dp = NULL;
    if (typeid(*p) == typeid(Derived))
    {
        dp = static_cast<Derived*>(p);
        dp->funcB();
    }
    else {
        p->funcA();
    }
}

int main(int argc, char const* argv[])
{
    Base* p = new Derived;
    cout << typeid(p).name() << endl;
    cout << typeid(*p).name() << endl;
    funcD(p);
    funcC(p);
    delete p;

    Base* dp = new Base;
    funcC(dp);
    funcD(dp);
    delete dp;
    return 0;
}