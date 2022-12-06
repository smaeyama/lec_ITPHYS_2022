#include <stdio.h>
/* 引数としてアドレスの値が送られてくるので、int 型へのポインタを宣言する*/
void swap_int(int *a, int *b)
/* a には呼び出し側の第１引数のアドレス、b には第 2 引数のアドレスが格納される*/
{
  int tmp;
  tmp = *b; *b = *a; *a = tmp;
}

int main(void)
{
  int a = 1, b = 2;
  printf("(before) a = %d, b = %d\n", a, b);
  swap_int(&a, &b); /* 交換したい変数 a と b のアドレスを渡す */
  printf("(after) a = %d, b = %d\n", a, b);
  return 0;
}
