#include <stdio.h>

void check_ascii_code(void){
  char ca[9];
  printf("### Check ASCII code 'a'=97\n");
  printf("%d\n",'a');
  printf("%c\n",'a');
  printf("%d\n",97);
  printf("%c\n",97);  /* %c は整数値をASCIIコード表に従って文字に変更して出力 */
  ca[0] = 97;  /* 文字配列は整数を格納している.'a'の文字コードは97。 */
  ca[1] = 0;   /* 終端文字'\0'の文字コードは0 */
  printf("%d\n",ca[0]);
  printf("%c\n",ca[0]);
  printf("%s\n",ca);
  printf("\n");
}

void importance_of_terminated_strings(void){
  char chr[] = "Moji";               /* chr は終端文字を含めて長さ5の配列 */
  char wrong[4] = {'a','b','c','d'}; /* 終端文字を含まない誤った文字配列 */
  char str[9] = {'X','Y','Z','\0'};  /* こちらは正しい */
  printf("### Check importance of terminated strings\n");
  printf("%s\n",chr);
  printf("%s\n",wrong);
  printf("%s\n",str);
  printf("Address of chr: %p\n",chr);
  printf("Address of wrong: %p\n",wrong);
  printf("Address of str: %p\n",str);
}

int main(void){

  check_ascii_code();

  importance_of_terminated_strings();

  return 0;
}
