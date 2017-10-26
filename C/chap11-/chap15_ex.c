#include <stdio.h>

void min_max(int *min, int *max, int col_vector[]);

int main(void)
{
  int i = 0, array[10], min, max;

  do {
    printf("数字を入力してください>");
    scanf("%d", &array[i]);
    i++;
  } while(array[i - 1] != -1);

  min_max(&min, &max, array);

  printf("max is %d, min is %d\n", max, min);

  return 0;
}


void min_max(int *min, int *max, int col_vector[])
{
  int i=0;
  *max = 0;
  *min = 100;

  while(col_vector[i] != -1){
    if (*max <= col_vector[i]){
      *max = col_vector[i];
    }
    if (*min >= col_vector[i]){
      *min = col_vector[i];
    }
    i++;
  }
  return;
}
