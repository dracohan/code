#include <bitset>
#include <iostream>
using namespace std;
int main() {
  float x = 0;
  char *ptr;
  ptr = (char *)&x;

  for (int i = 0; i < 8; i++)
    cout << (int)ptr[i]
         << " ";  //验证每个字节的ASCII码值，均为0，对应空字符'\0'。
  cout << endl;
  cout << ptr << endl;
  for (int i = 0; i < 8; i++)
    cout << bitset<8>((int)(*ptr++)) << " ";  //输出二进制位，共64位。
  cout << endl;

  return 0;
}
