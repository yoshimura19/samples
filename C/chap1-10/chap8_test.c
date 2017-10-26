#include<stdio.h>

int main(void){

  int no;

  printf("input the uniform number of person>");
  scanf("%d", &no);
  switch (no){
  case 1:
    printf("野比のび太\n");
    break;
  case 2:
    printf("源静香\n");
    break;
  case 3:
    printf("剛田武\n");
    break;
  case 4:
    printf("骨川スネ夫\n");
    break;
  default:
    printf("There's no person who has uniform number %d.", no);
    break;
  }

  return 0;
}
