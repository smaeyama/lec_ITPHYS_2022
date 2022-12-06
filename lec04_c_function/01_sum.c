#include <stdio.h>
int sum_int(int a, int b)
{
  return a+b;
}

int main(void)
{
  int c;
  c = sum_int(1, 2); /* 関数の呼び出し */
  printf("c=%d\n",c);
  return 0;
}
