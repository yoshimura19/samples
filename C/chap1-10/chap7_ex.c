#include<stdio.h>

int main(void){

  int year;

  printf("input the year>");
  scanf("%d", &year);

  if (year % 4 == 0){
    printf("Summer Olympic year %d\n", year);
  } else if(year % 2 == 0){
    printf("Winter Olympic year %d\n", year);
  } else {
    printf("Olympic is not held in %d\n", year);
  }


  return 0;
}
