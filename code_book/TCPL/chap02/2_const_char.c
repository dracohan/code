#include <stdio.h>

int main() {
  const char* a = NULL;
  if (a && !a[0]) 
    printf("a is empty\n");
  else 
    printf("a is NOT empty\n");
  return 0;
}
