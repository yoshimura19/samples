#include<stdio.h>

int is_Olympic(int year);  /* プロトタイプ宣言 */

enum {
  OLYMPIC_NON,
  OLYMPIC_SUMMER,
  OLYMPIC_WINTER,
};


int main(void)
{
  int year, hold;


  scanf("%d", &year);
  hold = is_Olympic(year);

  switch (hold) {
  case OLYMPIC_SUMMER:
    printf("Summer Olympic %d\n", year);
    break;
  case OLYMPIC_WINTER:
    printf("Winter Olympic %d\n", year);
    break;
  case OLYMPIC_NON:
    printf("There is no Olympic in %d\n", year);
    break;
  }


  return 0;
}


int is_Olympic(int year)
{
  if (year %2 == 0){
    if (year %4 == 0){
      return OLYMPIC_SUMMER;
    } else {
      return OLYMPIC_WINTER;
    }
  }
  else {
    return OLYMPIC_NON;
  }
}
