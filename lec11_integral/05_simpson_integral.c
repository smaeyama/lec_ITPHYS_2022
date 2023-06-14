#include <stdio.h>
#include <math.h>
double f(double x);
double simpson(int i, double h, double a);
int main(void)
{
  int m=64, n=2*m; /* 積分区間の分割数 */
  double a=1.0, b=2.0; /* 積分区間の下端と上端 */
  double h, sum;
  int i;
  h = (b-a)/n;
  sum = 0.0;
  for (i=0; i<m; i++) {
    sum += simpson(i,h,a); /* 各小区間毎の積分値を足し上げる */
  }
  printf("m=%d (n=%d): sum =%20.16f, ln2-sum =%e\n", m, n, sum, log(2.0)-sum);
  return 0;
}
/* 被積分関数 f(x)=1/x */
double f(double x) {
  return 1.0/x;
}
/* シンプソン法による数値積分 simpson = (h/3)*(f(x0)+ 4*f(x1)+ f(x2)) */
double simpson(int i,double h, double a) {
  double x0, x1, x2;
  x0 = a + 2*i*h;
  x1 = x0 + h;
  x2 = x1 + h;
  return (h/3.0) * (f(x0) + 4.0 * f(x1)  + f(x2));
}
