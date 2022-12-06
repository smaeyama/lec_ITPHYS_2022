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

  if (i>10) {
      printf( "%d is larger than 10.\n", i);
  } else if (i==2){
      printf( "%d is 2.\n", i);
  } else {
    printf( "%d\n",i);
  }
  return 0;
}
