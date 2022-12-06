#include <stdio.h>
int main(void){
  float x;
  x = 0.5;
  printf("x = %f\n",x);
  printf("&x = %p\n", &x); /* アドレスを表示 */
  printf("*(&x) = %f\n", *(&x)); /* アドレスにあるオブジェクトを表示 */
  return 0;
}
