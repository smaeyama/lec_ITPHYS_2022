#include <stdio.h>
#include <math.h>
double f(double x);
double trapezoid(int i, double h, double a);
double simpson(int i, double h, double a);
int main(void)
{
  int m=64, n=2*m;
  double a=1.0, b=2.0;
  double h, sumt, sums;
  int i;
  printf("#  n, error(trapezoid), error(simpson)\n");
  for (m=2; m<1024; m=m*2){
    n = 2*m;
    h = (b-a)/n;
    sumt = 0.0;
    for (i=0; i<n; i++) {
      sumt += trapezoid(i,h,a);
    }
    sums = 0.0;
    for (i=0; i<m; i++) {
      sums += simpson(i,h,a);
    }
    printf("%8d  %25.12e  %25.12e\n", n, log(2.0)-sumt, log(2.0)-sums);
  }
  return 0;
}
/* f(x)=1/x */
double f(double x) {
  return 1.0/x;
}
/* trapezoid = (h/2) * (f(x0) + f(x1)) */
double trapezoid(int i,double h, double a) {
  double x0, x1;
  x0 = a + i*h;
  x1 = x0 + h;
  return 0.5 * h * ( f(x0) + f(x1) ) ;
}
/* simpson = (h/3)*(f(x0)+ 4*f(x1)+ f(x2)) */
double simpson(int i,double h, double a) {
  double x0, x1, x2;
  x0 = a + 2*i*h;
  x1 = x0 + h;
  x2 = x1 + h;
  return (h/3.0) * (f(x0) + 4.0 * f(x1)  + f(x2));
}
