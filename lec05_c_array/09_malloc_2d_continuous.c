#include <stdio.h>
#include <stdlib.h>
#define vsize 4
#define hsize 3
int main(void){
  int i, j;
  float **a;
  a = (float **)malloc(vsize * sizeof(float *)); /* vsize個のポインタ配列を確保 */
  a[0] = (float *)malloc(vsize * hsize * sizeof(float)); /* vsize*hsize個の単精度実数配列を確保（a[0][0~vsize*hsize-1]までメモリ上連続） */
  for (i=0; i<vsize; i++){
    a[i] = a[0] + i*hsize; /* a[i][j]がa[0][i*hsize+j]を指すようにポインタの位置調整 */
  }

/* 適当に値を設定 */
  for (i=0; i<vsize; i++){
    for (j=0; j<hsize; j++){
      a[i][j] = (float)(i+j);
    }
  }
  
/* 二次元配列a[i][j]のアドレスと値を確認 */
  for (i=0; i<vsize; i++){
    for (j=0; j<hsize; j++){
      printf("%d,%d,%p, %f\n",i,j,&a[i][j],a[i][j]);
    }
  }

  free(a[0]); /* 開いたときの逆順で開放 */
  free(a);

  return 0;
}
