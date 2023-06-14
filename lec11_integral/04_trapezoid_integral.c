#include <stdio.h>
#include <math.h>
double f(double x);
double trapezoid(int i, double h, double a);
int main(void)
{
  int n=128; /* 積分区間の分割数 */
  double a=1.0, b=2.0; /* 積分区間の下端と上端 */
  double h, sum;
  int i;
  h = (b-a)/n;
  sum = 0.0;
  for (i=0; i<n; i++) {
    sum += trapezoid(i,h,a); /* 各小区間毎の積分値を足し上げる */
  }
  printf("n=%d: sum =%20.16f, ln2-sum =%e\n", n, sum, log(2.0)-sum);
  return 0;
}
/* 被積分関数 f(x)=1/x */
double f(double x) {
  return 1.0/x;
}
/* 台形公式による数値積分 trapezoid = (h/2) * (f(x0) + f(x1)) */
double trapezoid(int i,double h, double a) {
  double x0, x1;
  x0 = a + i*h;
  x1 = x0 + h;
  return 0.5 * h * ( f(x0) + f(x1) ) ;
}
