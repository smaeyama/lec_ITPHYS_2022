#include <stdio.h>
#include <stdlib.h> /* rand() 関数の定義がある*/
#include <time.h> /* time() 関数の定義がある*/
int main(void)
{
  FILE *fp;
  char buf[256],filename[]="rand.dat";
  int i,n;
  double x;
  /* データ数を入力*/
  printf("number ?\n");
  fgets(buf,sizeof(buf),stdin);
  if( sscanf(buf,"%d",&n) !=1 ){
    fputs("input error\n", stderr);
    exit(-1);
  }
  /* 書き出しファイルを開く*/
  if(NULL== (fp=fopen(filename,"w"))){
    fprintf(stderr, "Cannot open file: %s\n", filename);
    exit(1);
  }
  /* rand() のために実行時の時刻を「種」として与える*/
  srand((unsigned) time(NULL));
  for(i=0;i<n;i++){
    x = (double)rand()/RAND_MAX; /*0-1 の乱数(倍精度) にする*/
    fprintf(fp,"%lf\n",x);
    // printf("%lf\n",x);
  }
  fclose(fp);
  return 0;
}
