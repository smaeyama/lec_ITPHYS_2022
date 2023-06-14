#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
  char buf[64];
  float a, b, c;
  float x1, x2, p;
  printf("ax^2+bx+c=0: (a, b, c) = ");
  fgets(buf, sizeof(buf), stdin);
  if (sscanf(buf, "%f,%f,%f", &a, &b, &c) != 3) {
    fputs("Input error\n", stderr);
    exit(-1);
  }
  if(a==0){ /* 2 次方程式でない場合は終了*/
    fputs("a=0",stderr);
    exit(-2);
  }
  p = sqrt(b * b - 4 * a * c);
  x1 = (-b + p) / (2 * a); /* b とp が近いと桁落ちが発生*/
  x2 = (-b - p) / (2 * a);
  printf("x1 = %e, x2 = %e\n", x1, x2);
  return 0;
}
