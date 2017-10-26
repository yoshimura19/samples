#include <stdio.h>

int main(void)
{
  char str[32];

  /* gets(str); */
  /* puts(str); */

  fgets(str, sizeof(str), stdin);
  puts(str);

  return 0;
}
