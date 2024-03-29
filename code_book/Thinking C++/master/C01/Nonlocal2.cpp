//: C01:Nonlocal2.cpp
// Illustrates exceptions
#include <iostream>
using namespace std;

class Rainbow {
public:
  Rainbow() { cout << "Rainbow()" << endl; }
  ~Rainbow() { cout << "~Rainbow()" << endl; }
};

void oz() {
  Rainbow rb;
  for(int i = 0; i < 3; i++)
    cout << "there's no place like home\n";
  throw 47;
}

int main() {
  try {
    cout << "tornado, witch, munchkins...\n";
    oz();
  }
  catch (int) {
    cout << "Auntie Em! "
         << "I had the strangest dream..."
         << endl;
  }
} ///:~
