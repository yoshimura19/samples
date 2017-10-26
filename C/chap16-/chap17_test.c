#include <stdio.h>

#define FILENAME "test.txt"

int main(void)
{
  FILE *file;
  file = fopen(FILENAME, "w");
  fprintf(file, "Hello, world");
  fclose(file);

  return 0;
}
