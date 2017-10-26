#include<stdio.h>

int main(void){

  int r;
  double s;  //radius, square

  do {
    printf("input a radius>");
    scanf("%d", &r);
  } while (r < 0);

  s = r * r * 3.14;
  printf("the calculated area is %f\n", s);


  return 0;
}
