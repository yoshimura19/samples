#include<stdio.h>

int main(void){

  //double data;

  /* printf("input a number>"); */
  /* scanf("%lf", &data); */
  /* printf("%f\n", data); */

  /* int data1, data2; */

  /* printf("input two numbers(using space between numbers>)"); */
  /* //scanf("%d, %d", &data1, &data2);  //(using comma between numbers) */
  /* scanf("%d%d", &data1, &data2); */
  /* printf("%d %d\n", data1, data2); */

  int min, max, sum;
  
  /* 入力部分 */
  printf("input min value and max value(using comma between two numbers)>");
  scanf("%d, %d", &min, &max);
  
  /* 計算部分 */
  sum = (min + max) * (max - min + 1) / 2;

  /* 表示部分 */
  printf("the sum of %d~%d is %d\n", min, max, sum);
    
  return 0;
}
