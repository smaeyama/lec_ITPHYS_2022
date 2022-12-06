#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) /* 実行時にファイル名の引数をつけられるようにしておく*/
{
  FILE *fp;
  double data, sum=0.0;
  int i=0;
  char *fname;
  char buf[50];
  if (argc != 2 ){ /* コマンドに引数が1 つ付いているか？ */
    fputs("1st. argument should be a data filename\n", stderr);
    exit(-1);
  }
  fname = argv[1]; /* 最初のコマンドライン引数のアドレスを代入*/
  if ( (fp = fopen(fname, "r")) == NULL ){
    fprintf(stderr,"Can't open %s.\n", fname);
    exit(-1);
  }
  while(fgets(buf, sizeof(buf), fp) != NULL ) {
    if ( sscanf(buf, "%lf", &data) != 1 ) continue; // sscanf の返り値は入力データの個数
    /* sscanf ≠ 1 の場合、continue 文によって以下の処理がスキップされ、次のループに入る*/
    i++;
    sum += data; /* sum = sum + data の短縮表示. C 言語の最初の回参照*/
    printf("%3d: %lf\n", i, data);
  }
  fclose(fp);
  /* 読み込んだファイル中の数字の合計を出力する*/
  if (i == 0) {
    printf("No data in %s\n", fname);
  } else {
    printf("sum: %lf\n", sum);
  }
  return 0;
}
