#include <stdio.h>
#define vsize 2
#define hsize 3

void multiply(float a[vsize][hsize],float b[hsize],float c[vsize])
/*引数の部分は (float a[][hsize],float b[],float c[]) 等でも OK*/
{
  int i,j;
  for(i=0;i<vsize;i++){
    for(j=0;j<hsize;j++){
      c[i] += a[i][j] * b[j];
    }
  }
}

int main(void)
{
  int i;
  float a[vsize][hsize] = {{0.0,1.0,2.0},{1.0,2.0,3.0}};
  float b[hsize] = {0.0,1.0,2.0};
  float c[vsize] = {0.0,0.0};
  multiply(a,b,c); /* 配列の先頭アドレスを渡している */
  for(i=0;i<vsize;i++){
    printf("%f\n",c[i]);
  }
  return 0;
}
