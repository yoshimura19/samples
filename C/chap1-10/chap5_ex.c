#include<stdio.h>

int main(void){

  /* 変数の宣言 */
  int apple;
  double tax_rate;
  
  apple = 100;
  tax_rate = 1.05;

  printf("金額は%dです\n", (int)(apple * tax_rate));


  int a = 10000, b = 500, c = 3;

  printf("Aは %5d です。 \n", a);
  printf("Bは %5d です。 \n", b);
  printf("Cは %5d です。 \n", c);


  printf("Aは %05d です。 \n", a);
  printf("Bは %05d です。 \n", b);
  printf("Cは %05d です。 \n", c);


  
  return 0;
}
