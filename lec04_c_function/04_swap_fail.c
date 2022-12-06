#include <stdio.h>
/* 変数 a, b の値を交換したいが，交換できない例 */
void swap_int(int a, int b) /* 変数 a,b はここで作られる */
{
  int tmp;
  tmp = b; b = a; a = tmp;
  printf("(swap_int) a = %d, b = %d\n", a, b);
  /* この関数を抜ける時に変数 a, b, tmp は廃棄される */
}

int main()
{
  int a = 1, b = 2;
  swap_int(a, b);
  printf("(main) a = %d, b = %d\n", a, b);
  /* ここで a=2, b=1 となっていて欲しい。でも、実際は、a=1, b=2 のまま */
  return 0;
}
