#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ACC 1.0e-12

int main(void){
  double x, xt;
  double f(double), df(double); /*引数が倍精度実数の関数と定義*/
  int i=0;
  char buf[30];
  printf("initial guess ?");
  fgets(buf,sizeof(buf),stdin); /*初期の当てずっぽうの解の入力*/
  if (sscanf(buf,"%lf",&x) != 1) {
    fputs("input error\n", stderr);
    exit(-1);
  }
  do {
    i++;
    xt=x;
    x=x-f(x)/df(x);  /* x2 = x1 - f(x1)/f’(x1) */
    printf("i=%d,x=%25.16f xt-x=%25.16f\n", i, x, xt-x);
  } while(x-xt >= ACC || xt-x >= ACC); /* |xt-x|<=ACC */
  return 0;
}

double f(double x)
{
  return tanh(x);
}
double df(double x)
{
  double s;
  s = cosh(x);
  return 1.0/(s*s);
}
