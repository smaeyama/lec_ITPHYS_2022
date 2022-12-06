# include <stdio.h>
int main(void) {
  char buf[50];
  int i;
  double number, sum = 0.0;
  for(i=1; i <= 10; ++i){
    printf("Enter a n%d: ",i);
    fgets(buf,sizeof(buf),stdin);
    if (sscanf(buf,"%lf",&number) != 1){ /* buf からdble 型(%lf) でnumber を読み取る*/
      printf("Not a number, continue!\n");
      //--i;
      i--;
      continue; /* 数字以外の文字が入力されたら、カウンターを戻してもう一度*/
    }
    if(number < 0.0){
      continue; /* 負の数字が入力されたら無視する*/
    }
    if(number == 0.0){
      break; /* 0 が入力されたら終了*/
    }
    sum += number; // sum = sum + number;
  }
  printf("Sum = %.2lf\n",sum);
  return 0;
}
