#include <iostream>
using namespace std;

// Assignment 3b

int main()
{
  const int a = 1;  // 変数は変更出来ない
  int b = a;
  int* const p = &b;  // pの保持するアドレスが不変に
  int* q = p;         // pの保持するアドレスをポインタ変数qに格納
                      // 例えばp = &aはエラー
  const int* r = &a;  // rはaのアドレス保持し*rでアクセスする値(今はaの値)を不変に
                      // a = 2はエラー
                      // r = &c (新しい変数c)はok
  return 0;
}
