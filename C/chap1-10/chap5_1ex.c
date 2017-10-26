#include<stdio.h>

int main(void){

  int pokari, milk;  //買ったもの
  int money;
  int payment;       //支払い金額
  int change;        //おつり
  double tax_rate;
  
  pokari = 198;
  milk = 138;
  money = 1000;
  tax_rate = 1.05;

  payment = (int)((pokari + 2*milk)*tax_rate);
  change = money - payment;

  printf("おつりは%dです。\n", change);

  return 0;
}
