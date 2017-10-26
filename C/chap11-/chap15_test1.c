#include <stdio.h>

void func(int *pvalue);  /* プロトタイプ宣言(intへのポインタ型) */

int main(void)
{
  int value = 10;
  printf("&value = %p\n", &value);  //valueのアドレス表示
  func(&value);            // valueのアドレスを渡す

  printf("value  = %d\n", value);
  /* アドレスを渡した先(関数で演算して書き換え)の結果が入る */

  return 0;
}

void func(int *pvalue)
{
  printf("pvalue = %p\n", pvalue);  // 関数にアドレスが移っていることの確認
                                   //pvalueは何もつけない時がポインタ変数モードであることに注意
  *pvalue = 100;     //通常変数モード
  return;
}
