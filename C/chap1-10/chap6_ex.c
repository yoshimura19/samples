#include<stdio.h>

int main(void){

  int raw_price;
  int discount_10, discount_30, discount_50, discount_80;

  
  printf("input price>");
  scanf("%d", &raw_price);

  discount_10 = (int)(raw_price * 0.9);
  discount_30 = (int)(raw_price * 0.7);
  discount_50 = (int)(raw_price * 0.5);
  discount_80 = (int)(raw_price * 0.2);

  printf("raw price is %d ,and discount prices are below\n", raw_price);
  printf("10%%OFF %d\n30%%OFF %d\n50%%OFF %d\n80%%OFF %d\n", discount_10, discount_30, discount_50, discount_80);
  
  return 0;
}
