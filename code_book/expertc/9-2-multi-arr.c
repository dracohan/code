#include <stdio.h>

int main() {
  int apricot[2][3][5] = {
      {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}},
      {{16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}, {26, 27, 28, 29, 30}}};

  int (*b)[5] = apricot[0];
  int *t = apricot[0][0];

//   printf("sizeof apr[0]: %d\n", sizeof(apricot[0]));
  printf("sizeof r[0]: %d\n", sizeof(b[0])); //b[0] is {1, 2, 3, 4, 5}

  
//   printf("sizeof t[0]: %d\n", t[1]);
  // printf("r: %p\n", r++);
  // printf("t: %p\n", t++);

  // printf("r: %p\n", r++);
  // printf("t: %p\n", t++);
  return 0;
}
