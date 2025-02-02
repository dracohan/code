//: C11:MutexEvenGenerator.cpp
// Preventing thread collisions with mutexes.
//{L} ZThread
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/Mutex.h"
#include <iostream>
using namespace ZThread;
using namespace std;

class MutexEvenGenerator : public Generator {
  int currentEvenValue;
  Mutex lock;
public:
  MutexEvenGenerator() { currentEvenValue = 0; }
  ~MutexEvenGenerator() {
    cout << "~MutexEvenGenerator" << endl;
  }
  int nextValue() {
    lock.acquire();
    currentEvenValue++;
    Thread::yield();
    currentEvenValue++;
    int rval = currentEvenValue;
    lock.release();
    return rval;
  }
};

int main() {
  EvenChecker::test<MutexEvenGenerator>();
} ///:~
