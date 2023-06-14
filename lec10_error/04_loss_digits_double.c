#include <stdio.h>
int main(void)
{
  int n = 1000, i;
  double k, sum1, sum2;
  sum1 = 0.0;
  for (i = 0; i < n; i++){
    k = 1.0 + i;
    sum1 = sum1 + 1.0/k;
  }
  sum2 = 0.0;
  for (i = 0; i < n; i++){
    k = n - i;
    sum2 = sum2 + 1.0/k;
  }
  printf("Sum 1 (from large to small): %e\n", sum1);
  printf("Sum 2 (from small to large): %e\n", sum2);
  return 0;
}
