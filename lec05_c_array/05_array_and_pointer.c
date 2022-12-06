#include <stdio.h>
int main(void){
  float a[5];
  float *p;
  a[0] = 0.5;
  a[1] = 1.5;
  a[2] = 2.5;
  printf("a[0]=%f, &a[0]=%p\n",a[0],&a[0]);
  printf("a[1]=%f, &a[1]=%p\n",a[1],&a[1]);
  printf("a[2]=%f, &a[2]=%p\n",a[2],&a[2]);
  printf("a[3]=%f, &a[3]=%p\n",a[3],&a[3]); /* a[3]やa[4]の値は不定だが、アドレスは決まっている */
  printf("a[4]=%f, &a[4]=%p\n",a[4],&a[4]);
  printf("  a=%p\n",a);
  printf("a+1=%p\n",a+1);
  printf("a+2=%p\n",a+2);
  printf("a+3=%p\n",a+3);
  printf("a+4=%p\n",a+4);
  p = a; /* ポインタpに対して配列の先頭アドレス a (=&a[0])を格納する */
  printf("p[0]=%f, &p[0]=%p\n",p[0],&p[0]);
  printf("p[1]=%f, &p[1]=%p\n",p[1],&p[1]);
  printf("p[2]=%f, &p[2]=%p\n",p[2],&p[2]);
  printf("p[3]=%f, &p[3]=%p\n",p[3],&p[3]);
  printf("p[4]=%f, &p[4]=%p\n",p[4],&p[4]);
  printf("  p=%p\n",p);
  printf("p+1=%p\n",p+1);
  printf("p+2=%p\n",p+2);
  printf("p+3=%p\n",p+3);
  printf("p+4=%p\n",p+4);
  return 0;
}
