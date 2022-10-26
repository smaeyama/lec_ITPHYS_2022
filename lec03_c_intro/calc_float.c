#include <stdio.h>
int main(){
  float fahr, celsius;
  fahr = 0.0;
  while (fahr <= 300.0){
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f  %6.1f\n",fahr,celsius);
    fahr += 20.0;
  }
  return 0;
}
