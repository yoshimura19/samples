#include <stdio.h>

void maxmin(int array[], int *max, int *min);

int main(void)
{
  int i = 0, array[10], max, min;

  do {
    printf("%d 番目の数:", i + 1);
    scanf("%d", &array[i]);
    i++;
  } while (array[i - 1] != -1);

  maxmin(array, &max, &min);

  return 0;
}
