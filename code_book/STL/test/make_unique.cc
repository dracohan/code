#include <memory>
#include <iostream>

using namespace std;

class Result {
public:
  Result() : _x(-1) {}
  int _x;
};

int main() {
  // auto &&r  = std::make_unique<Result>();
  Result r;
  std::cout << "r: " << r._x << std::endl;
}