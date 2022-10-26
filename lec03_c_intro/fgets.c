#include <stdio.h>
#include <stdlib.h> /* 下のexit を用いるのに必要*/
int main(void)
{
  char buf[50]; /* 文字列の宣言この場合49(=50-1) 文字まで読み込める．*/
  int i1,i2;
  int num;
  printf("please input signed integer, i1, i2 = ");
  fgets(buf,sizeof(buf),stdin); /* 文字列buf として読み込む*/
  num = sscanf(buf,"%d,%d",&i1,&i2);
  printf("%d\n",num);
  if (num != 2) { /* 数値に変換; !=: Not Equal */
    fputs("input error\n", stderr);
    /* 読み込む数の個数が間違っていたら終了*/
    exit(-1); /* プログラムから抜けて終了*/
  }
  printf("singed integer i = %d %d\n",i1,i2);
  return 0;
}
