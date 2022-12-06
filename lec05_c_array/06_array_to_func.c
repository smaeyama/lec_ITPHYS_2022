#include <stdio.h>
void vec2(float *a, int n)
/* void vec2(float a[], int n) でも良い */
{
  int i;
  for(i = 0; i < n; i++){
    a[i] = 2.0 * a[i];
  }
}

int main()
{
  int i,n;
  float a[]={1.5,2.0,2.5}; /* 1 次元の配列の宣言 */
  n = sizeof(a)/sizeof(a[0]); /* 配列の要素数を決める方法 */
  vec2(a,n); /* 要素数 n の配列のアドレス a を関数に渡す */
  for(i = 0; i < n; i++){
    printf("%5.2f", a[i]);
  }
  printf("\n");
  return 0;
}
