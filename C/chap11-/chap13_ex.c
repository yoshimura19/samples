#include <stdio.h>

int main(void)
{
  int data[10];
  int i;

  for (i = 0; i < 10; i++){
    printf("input a %dth number>", i+1);
    scanf("%d", &data[i]);
  }

  for (i = 0; i < 10; i++){
    printf(" %d :", data[9-i]);
  }
  printf("\n");

  return 0;
}
