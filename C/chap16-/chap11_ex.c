#include<stdio.h>

int is_Olympic(int);  /* プロトタイプ宣言 */


int main(void)
{
  int year, hold;

  scanf("%d", &year);
  hold = is_Olympic(year);

  switch (hold) {
  case 1:
    printf("Summer Olympic %d\n", year);
    break;
  case 2:
    printf("Winter Olympic %d\n", year);
    break;
  case 3:
    printf("There is no Olympic in %d\n", year);
    break;
  }


  return 0;
}


int is_Olympic(int year)
{
  if (year %2 == 0){
    if (year %4 == 0){
      return 1;
    } else {
      return 2;
    }
  }
  else {
    return 3;
  }
}
