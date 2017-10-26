#include <iostream>
using namespace std;

// Assignment 2b

int main()
{
  int a = 1;
  int *p = &a;   // pはaのアドレスを保持するポインタオブジェクト
  int &b = *p;   // 参照演算子を使いpの保持するaのアドレスにアクセスし、それを参照しbに格納(bはaの参照になった)
                 // つまり、*pはaを参照するために経由した。
  int c = 2;
  p = &c;        // pにcのアドレスを格納(格納するアドレスが&aから&cに)
  b = 3;         // bはaの参照になっているのでaの値も変わる。
  cout << "a = " << a << endl;   // bはaの参照になっているので、bの値=aの値  出力は3
  cout << "c = " << c << endl;   // pには新しいcのアドレスが入っているので、bの変更は関係ない。出力は2

  return 0;
}
