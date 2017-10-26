#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char str[32];
  int val;

  fgets(str, sizeof(str), stdin);
  val = atoi(str);
  printf("%d\n", val * val);

  return 0;
}
