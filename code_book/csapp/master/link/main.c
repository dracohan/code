/* main.c */
/* $begin main */
int sum(int *a, int n);

int array[2] = {1, 2};

int main() {
  int val = sum(array, 2);
  printf("val: %d\n", val);
  return val;
}
/* $end main */
