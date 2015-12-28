// 2.cc
#include <iostream>
#include <stack>
using namespace std;

template <typename T> class MinStack {
private:
      stack<T> stacks, mins;

public:
      MinStack() {}
      ~MinStack() {}

      void push(const T & x) {
            stacks.push(x);
            if (mins.empty() || x <= mins.top())
                  mins.push(x);
      }

      void pop() {
            T x = stacks.top();
            stacks.pop();
            if (x == mins.top()) mins.pop();
            return;
      }

      T top() const{
            return stacks.top();
      }

      T get_min() {
            return mins.top();
      }
};

int main() {
      MinStack<int> s;
      s.push(6);
      s.push(7);
      s.push(5);
      s.push(9);
      s.push(3);
      cout << s.get_min() << endl;
      s.pop();
      s.pop();
      s.pop();
      cout << s.get_min() << endl;
      return 0;
}