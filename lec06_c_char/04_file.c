#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  FILE *fp;
  char filename[] = "./test1.txt";
  /* 1. 名前が”test1.txt ”のファイルを”write mode ”でオープンする*/
  /* 2. fopen の返り値であるファイルポインタをfp に代入する*/
  /* 3. そのfp がNULL であったらエラー処理*/
  fp = fopen(filename, "w");
  if(NULL == fp){
    fprintf(stderr, "Cannot open file: %s\n", filename);
    exit(1); /* エラーの場合は終了*/
  }
  fprintf(fp, "Success %dst time!\n", 1);
  fclose(fp); /* 忘れずに！！ */
  return 0;
}
