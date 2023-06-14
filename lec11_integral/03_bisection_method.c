#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ACC 1.0e-12

int main(void){
  double a,b,c,fa,fb,fc;
  double f(double); /*引数が倍精度実数の関数と定義*/
  int i;
  char buf[30];

  printf("initial guess a,b ? ");
  fgets(buf,sizeof(buf),stdin); /*初期の当てずっぽうの解の入力*/
  if (sscanf(buf,"%lf,%lf",&a,&b) != 2) {
    fputs("input error\n", stderr);
    exit(-1);
  }

  fa = f(a); fb = f(b);
  if(fa*fb > 0.0){ /*f(a) と f(b) が同符号の場合は終了*/
    printf("fa & fb should have opposite signs\n");
    exit(0);
  }

  /*解xは a<x<b (または b<x<a) の範囲にある*/
  i=0;
  do{
    i++;
    c = 0.5 * (a + b);
    fc = f(c);
    if(fc==0.0){ /*x=c が解なのでここで終了*/
      break;
    } else if (fa*fc <= 0.0){ /*解はaとcの間に.端点bの値をcに置き換え*/
      b = c; fb = fc;
    } else{ /*解はbとcの間に.端点aの値をcに置き換え*/
      a = c; fa = fc;
    }
    printf("i=%d,f(%20.16f)=%20.16f, f(%20.16f)=%20.16f\n", i,a,fa,b,fb);
  } while(fabs(b-a) >= ACC );
  printf("f(%20.16f)=%9.2f\n",c,fc);
  return 0;
}

double f(double x)
{
  return tanh(x);
}
