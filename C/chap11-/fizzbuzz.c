#include<stdio.h>

int main(void)
{

  int i;
  int n;

  printf("input the last number>");
  scanf("%d", &n);

  for (i=1; i < n + 1; i++){
    if (i % 3 == 0 && i % 5 == 0){
      printf("fizz buzz\n");
    } else if (i % 3 == 0){
      printf("fizz\n");
    } else if (i % 5 == 0){
      printf("buzz\n");
    } else {
      printf("%d\n1", i);
    }
  }

  return 0;
}
