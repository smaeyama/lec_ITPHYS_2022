#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int i, n = 100;
  float x, sum, sum2;
  x = 1.0 / n; /* 0.01 を計算しているつもり*/
  sum = 0;
  for (i = 0; i < n; i++){
    sum += x;
  }
  printf("sum = %.10f\n", sum); /* 1 / n * n だから1 に戻るはず... */
  if (sum == 1.0) {
    printf("Sum == 1\n");
  } else {
    printf("Sum != 1\n");
  }
  return 0;
}
