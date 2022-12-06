#include <stdio.h>

void add1_call_by_value(float arg){
  printf("# add1_call_by_value\n");
  printf("arg=%f, Address of arg: %p\n",arg,&arg);
  arg = arg + 1.0;
  printf("arg=%f, Address of arg: %p\n",arg,&arg);
  printf("\n");
}

void add1_call_by_reference(float *arg){
  printf("# add1_call_by_reference\n");
  printf("*arg=%f, Address of arg: %p\n",*arg,arg);
  *arg = *arg + 1.0;
  printf("*arg=%f, Address of arg: %p\n",*arg,arg);
  printf("\n");
}

int main(void){
  float x = 0.5;
  printf("  x=%f, Address of   x: %p\n",x,&x);
  add1_call_by_value(x); /* 値渡しで定義される関数を呼び出す */
  printf("  x=%f, Address of   x: %p\n",x,&x);
  add1_call_by_reference(&x); /* 参照渡しで定義される関数を呼び出す */
  printf("  x=%f, Address of   x: %p\n",x,&x);
  return 0;
}
