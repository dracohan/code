#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class Result {
public:
  Result() : _x(-1) {}
  int _x;
};

// std::unique_ptr<Result> alloc() {
// Result&& alloc() {
vector<int>&& alloc() {
  // auto &&r  = std::make_unique<Result>();
  // Result r; 
  vector<int> v = {1,2,3};
  return std::move(v);
  // return v;
}

int main() {
  auto &&c = alloc();
  // Result r;
  std::cout << "r: " << c.size() << std::endl;
}