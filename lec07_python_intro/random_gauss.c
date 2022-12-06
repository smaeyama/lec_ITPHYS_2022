#include <stdio.h>
#include <stdlib.h> /* rand() 関数の定義がある*/
#include <math.h>
#ifndef M_PI
#define M_PI 3.1415926535897932
#endif

#define N 128 /* 生成する乱数の個数 */

double box_muller()
{
  /* Box-Muller法により正規乱数を生成する */
  double r1, r2, rg;
  r1 = ((double)rand()+1.0)/((double)RAND_MAX+1.0);
  r2 = ((double)rand()+1.0)/((double)RAND_MAX+1.0);
  rg = sqrt(-2*log(r1))*cos(2*M_PI*r2);
  return rg;
}

int main(void)
{
  FILE *fp;
  char buf[256],filename[]="rand.dat";
  int i;
  double x;
  /* 書き出しファイルを開く*/
  if(NULL== (fp=fopen(filename,"w"))){
    fprintf(stderr, "Cannot open file: %s\n", filename);
    exit(1);
  }
  /* ファイルに生成した乱数の順番と値を書き出す */
  for(i=0;i<N;i++){
    x = box_muller();
    fprintf(fp,"%d  %lf\n",i,x);
  }
  fclose(fp); /* ファイルは必ず閉じる */
  return 0;
}
