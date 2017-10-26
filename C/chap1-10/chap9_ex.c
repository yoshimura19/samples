#include<stdio.h>

     /* かけ算九九プログラム */
int main(void){

  int i, j;

  for(i = 1; i <= 9; i++){
    for(j = 1; j <= 9; j++){
      printf("%02d ", i*j);
    }
    printf("\n");
  }



  return 0;
}
