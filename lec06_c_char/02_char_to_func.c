#include <stdio.h>
void print_message(char *message) /* 文字列型配列の先頭アドレスが来るので*/
/* char message[] と書いても良い*/
{
  printf("%s\n", message);
}
int main(void)
{
  char c[] = "abc";
  print_message(c); /* print_message("abc"); でも良い*/
  return 0;
}
