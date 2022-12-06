#include <stdio.h>
int sum_int(int a, int b)
{
  int d;
  d = a+b;
  a = 99;
  printf("a=%d\n",a);
  printf("b=%d\n",b);
  return d;
}

int main()
{
  int a = 1, b = 2, c;
  /* 変数 a, b の値をコピーして sum_int() に渡す。計算結果を返り値として */
  /* c に代入する。 */
  printf("a=%d\n",a);
  printf("b=%d\n",b);
  printf("c=%d\n",c);
  c = sum_int(a, b);
  printf("a=%d\n",a);
  printf("b=%d\n",b);
  printf("c=%d\n",c);
  return 0;
}
