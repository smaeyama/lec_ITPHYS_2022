#include <stdio.h>
/* プロトタイプ宣言 */
void print_message(char *message); /* 関数を使用する前に宣言の必要有り */

int main(void)
{
  print_message("Hello, world\n");
  return 0;
}

void print_message(char *message) /* 関数の呼び出しの後に定義 */
{
  printf("%s", message);
}
