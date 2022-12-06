#include <stdio.h>
#include <stdlib.h>
#define LINE_MAX 512
double heikin3(double a1, double a2, double a3)
{
  return (a1+a2+a3)/3.0;
}
int main(void)
{
  FILE *fp;
  char filename[] = "sample_3num.dat";
  char line[LINE_MAX];
  double d1, d2, d3;
  if (NULL == (fp = fopen(filename, "r"))) {
    fprintf(stderr, "Cannot open file: %s\n", filename);
    exit(1);
  }
  while(1) {
    if (NULL == fgets(line, sizeof(line), fp)) break; /* ファイルの終わり(EOF) になったら終了*/
    if (3 == sscanf(line, "%lf %lf %lf", &d1, &d2, &d3)){
    /* ファイルから1 行ごとに３つの数字を読み込み平均を出力する*/
      fprintf(stdout, "%f\n", heikin3(d1, d2, d3));
    }
  }
  fclose(fp);
  return 0;
}
