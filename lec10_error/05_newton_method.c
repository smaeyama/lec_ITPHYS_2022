#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ACC 1.0e-12 /* 収束判定基準値を決める */
int main(void){
  double a, x, xt, res;
  char buf[64];
  double f(double,double), dfdx(double);
  printf("input a positive number : ");
  if (fgets(buf, sizeof(buf), stdin) == NULL ||
      sscanf(buf, "%lf", &a) != 1){ /* 正の定数aの読み込み */
    fputs("Input error\n", stderr);
    exit(-1);
  }
  x = a; /* 適当な初期推定値を与える */
  do {                         /* Newton-Raphson法の反復開始 */
    xt = x;
    x = xt - f(x,a) / dfdx(x); /* 解の更新 */
    res = fabs(x-xt);          /* 誤差の見積もり */
    printf("x=%25.16f, |xt-x|=%25.16f\n", x, res);
  } while (res >= ACC); /* |xt-x|<=ACC の場合に収束とみなし反復終了 */
  printf("sqrt(%f)=%25.16f\n", a, x);
  return 0;
}

double f(double x, double a){
  return x*x - a;
}
double dfdx(double x){
  return 2*x;
}
