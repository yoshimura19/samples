#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i;
  int *heap;
  int *heap2;

  heap = (int *)malloc(sizeof(int) * 10);
  if (heap == NULL) exit(0);

  for (i=0;i < 10; i++){
    heap[i] = i;
  }
  printf("%d\n", heap[5]);


  heap2 = (int *)malloc(sizeof(int) * 10);
  if (heap2 == NULL) exit(0);
  heap2 = (int *)realloc(heap2, sizeof(int) * 100);

  for (i=0;i < 10; i++){
    heap2[i] = i;
  }
  printf("%d\n", heap2[4]);


  free(heap);
  free(heap2);

  return 0;
}
