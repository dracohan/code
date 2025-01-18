#include <iostream>

using namespace std;

class Foo  {public: int val; Foo *pnext;};

void foo_bar() {
  Foo bar;
  if (bar.val) 
    cout << "bar.bar= " << bar.val << endl;

  if (bar.pnext)
    cout << "pnext: " << bar.pnext << endl;
}
int main() {
  cout << "test" << endl;
  foo_bar();
  return 0;
}