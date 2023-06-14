#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ACC 1.0e-12
int main(void){
  double a, x, xt, res;
  double f(double,double), dfdx(double,double);
  int i;
  a = 1000000;
  printf("# Find a root of (x - sqrt(a))^2 = 0 with a = 1000000\n");
  printf("# Iteration, x, error\n");
  x = a; /* 適当な初期推定値 */
  i = 0;
  do {
    xt = x;
    x = xt - f(x,a) / dfdx(x,a);
    res = fabs(x-xt);
    i++;
    printf("%8d %25.16f %25.16f\n", i, x, fabs(sqrt(a)-x));
  } while (res >= ACC);
  return 0;
}

double f(double x, double a){
  return (x - sqrt(a))*(x - sqrt(a));
}
double dfdx(double x, double a){
  return 2*(x - sqrt(a));
}
