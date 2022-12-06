#include <stdio.h>
int main(void)
{
  int x = 1, y = 2; /* int 型の変数、x, y の宣言とその初期化*/
  int *p = &x; /* int 型変数へのポインタの宣言．p は int へのポインタである.*/
          /* “ *p ”は int 型であるという意味．つまり, p はアドレスを示している．*/
  /*p = &x;  p に x のアドレスを格納 (*p は x を示す) */
  printf("### p = &x ###\n");
  printf(" x=%d, Address of x: %p\n",x,&x);
  printf(" y=%d, Address of y: %p\n",y,&y);
  printf("*p=%d, Address of p: %p\n",*p,p);
  printf("\n");

  y = *p; /* アドレス p の中身 (int 型) を y に代入．つまり，y = x と等価*/
  *p = 2; /* x = 2 と等価*/
  printf("### y = *p; *p=2 ###\n");
  printf(" x=%d, Address of x: %p\n",x,&x);
  printf(" y=%d, Address of y: %p\n",y,&y);
  printf("*p=%d, Address of p: %p\n",*p,p);
  printf("\n");

  y += 5;
  printf("### y += 5 ###\n");
  printf(" x=%d, Address of x: %p\n",x,&x);
  printf(" y=%d, Address of y: %p\n",y,&y);
  printf("*p=%d, Address of p: %p\n",*p,p);
  printf("\n");

  return 0;
}
