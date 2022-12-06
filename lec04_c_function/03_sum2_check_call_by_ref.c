#include <stdio.h>
int sum_int(int a, int b)
{
  int d;
  d = a+b;
  a = 99;
  return d;
}

int main()
{
  int a = 1, b = 2, c;
  printf("a=%d\n",a);
  printf("b=%d\n",b);
  printf("c=%d\n",c);
  c = sum_int(a, b);
  printf("a=%d\n",a);
  printf("b=%d\n",b);
  printf("c=%d\n",c);
  return 0;
}
