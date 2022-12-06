#include <stdio.h>
#include <stdlib.h> /* malloc の使用に必要なライブラリ */
#define BUF_SIZE 256 /* 定数として定義する */

void vec2(float *a, int n)
{
  int i;
  /* printf("%ld %ld\n",sizeof(a),sizeof(a[0])); */
  for(i = 0; i < n; i++){
    a[i] = 2.0 * a[i];
  }
}

int main()
{
  int i,matrix_size;
  float *a;
  char buf[BUF_SIZE];

  /* ベクトルの大きさを取得 */
  printf("Matrix size = ");
  fgets(buf, sizeof(buf), stdin);
  if (1 != sscanf(buf, "%d", &matrix_size) || matrix_size < 1) {
    fprintf(stderr, "Invalid Matrix size!\n");
    exit(1);
  }

  /* ベクトルを動的に開く */
  if (NULL == (a = (float *)malloc(sizeof(float) * matrix_size))) {
  /* float の容量 × matrix_size のメモリ領域を malloc 関数で確保 */
  /* 確保したメモリを float 型ポインタ a へキャストしている */
    fprintf(stderr, "Cannot allocate memory!\n");
    exit(1);
  }

  /* 各成分毎にベクトルの値を入力する */
  for(i = 0; i < matrix_size; i++){
    printf("please input vector element %d = ",i+1);
    fgets(buf,sizeof(buf),stdin);
    if (sscanf(buf,"%f\n",&a[i]) != 1) { /* ポインタ a を配列と同様に扱うことができる */
      fputs("input error\n", stderr);
      exit(1);
    }
  }

  vec2(a,matrix_size); /* 要素数 n の配列のアドレス a を関数に渡す */

  for(i = 0; i < matrix_size; i++){
    printf("%5.2f ", a[i]);
  }
  printf("\n");

  free(a); /* 配列のメモリの解放: 非常に重要 */

  return 0;
}
