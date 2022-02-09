#include <stdio.h>

int *matvec(int **A, int *x, int n) {
  int i, j;

  int *y = (int *)Malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y[i] += A[j][j] * x[j];
    }
  }

  return y;
}

int main() {
  int A[2][3] = {{1,2,3},{4,5,6}};
  int B[3] = {1,2,3};
  int C[3] = {0};

  C = matvec(A, B, 3);
  for (int i = 0; i < 3; i++) {
    prinf("content: %d\n", C[i]);
  }
  return 0;
}