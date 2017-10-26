#include <stdio.h>
#include <string.h>

int main(void)
{
  char fname[256], Iname[256];

  printf("input your family name>");
  scanf("%s", fname);

  printf("input your first name>");
  scanf("%s", Iname);

  strcat(fname, Iname);
  printf("your full name is %s\n", fname);

  return 0;
}
