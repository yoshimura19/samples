#include<stdio.h>

int main(void){

  double money = 1;
  int month = 1;

  while (money < 1000000) {
    printf("%02d has passed : %0.7f yen \n", month, money);
    money *= 2;
    month ++;
  }
  printf("Money has reached 10 million when %02d has passed : %0.7f yen \n", month, money);



  
  return 0;
}
