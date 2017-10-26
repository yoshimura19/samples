#include <stdio.h>

int main(void)
{
  /* int i; */
  
  /* printf("%p\n", &i); */
  /* i = 3; */
  /* printf("%p\n", &i); */

  int i1, i2, i3;
  
  printf("i1(%p)\n", &i1);
  printf("i2(%p)\n", &i2);
  printf("i3(%p)\n", &i3);

  /* intは4byteなので4番ずれの連番 */
  
  return 0;
}
