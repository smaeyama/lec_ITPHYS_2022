#include <stdio.h>
#include <math.h>
int main(void){
  int i;
  double c, d;
  for (i=0; i<10; i++){
    c = 3.14159265359 * i / 10.0;
    d = sin(c);
    printf("sin(%.3f) = %.3f\n", c, d);
  }
  return 0;
}
