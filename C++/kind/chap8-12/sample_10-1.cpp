#include <iostream>
using namespace std;

// global変数
int a = 0;

int main()
{
  int a = 0;

  //a++;

  /* グローバル変数と同じものをローカル変数で宣言した場合、
     グローバル変数は隠されるため、グローバル解決演算子::
     を使ってアクセスする。
  */

  ::a++;

  cout << ::a << '\n';

  return 0;
}
