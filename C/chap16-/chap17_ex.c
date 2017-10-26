#include <stdio.h>

int main(void)
{
  FILE *fp;
  fp = fopen("test1.csv","w");
  fprintf(fp, "番号,名前,テストの平均点\n");

  fprintf(fp, "1,野比のび太,0\n");
  fprintf(fp, "2,源静香,90\n");
  fprintf(fp, "3,剛田武,40\n");
  fprintf(fp, "4,骨川スネ夫, 70,\n");

  fclose(fp);

  return 0;
}
