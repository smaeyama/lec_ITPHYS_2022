#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  char buf[50];
  int i;
  printf("please input signed integer i = ");
  fgets(buf,sizeof(buf),stdin); /* 文字列の読み込み． 前回参照*/
  if (sscanf(buf,"%d",&i) != 1) {
    fputs("input error\n", stderr);
    exit(-1);
  }
  switch(i) {
    case 1:
      printf( "1\n" ); /* break が無いのでcase 2:に侵入する*/
    case 2:
      printf( "2\n" );
      break; /* break があるのでここで終了*/
    default:
      printf( "\?\n"); /* i が1,2 のいずれでもないとき*/
      break;
  }
}
