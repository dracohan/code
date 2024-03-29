#include <iostream>
#include <iterator>
#include <numeric>


using namespace std;

int main() {
  const int N = 10;
  int A[N];
  fill(A, A+N, 1);
  cout << "A:                ";
  copy(A, A+N, ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "Partial sum of A: ";
  partial_sum(A, A+N, ostream_iterator<int>(cout, " "));
  cout << endl;
}
