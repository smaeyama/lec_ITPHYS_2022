#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
  char buf[64];
  double x;
  printf("Calculate sqrt(1+x)-1: (x) = ");
  fgets(buf, sizeof(buf), stdin);
  if (sscanf(buf, "%lf", &x) != 1){
    fputs("Input error\n", stderr);
    exit(-1);
  }
  printf("sqrt(1+x)-1 = %e\n", sqrt(1+x)-1);
  printf("Rationalized sqrt(1+x)-1 = %e\n", x/(sqrt(1+x)+1));
  return 0;
}
