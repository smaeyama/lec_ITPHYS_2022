#include <stdio.h>
int main(){
  int fahr, celsius;
  fahr = 0;
  while (fahr <= 300){
    celsius = 5 * (fahr - 32) / 9;
    printf("%03d  %7d\n",fahr,celsius);
    fahr += 20;
  }
  return 0;
}
