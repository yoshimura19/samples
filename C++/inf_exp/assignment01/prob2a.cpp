#include <iostream>
using namespace std;

// Assignment 2a

int main()
{
  {
    int a = 1;
    int &b = a;  // int型のbを宣言し、bにはaのアドレスを格納する(bはaの参照)
                 // なので、bはaと同じアドレスを持つ変数。
    int* p = &b; // pはbのアドレスを保持するポインタオブジェクト
    *p = 2;      // ポインタオブジェクトpに参照演算子を使って(a(b)のアドレスにアクセスし)代入
    cout << a << endl;   // 出力は2
  }

  {
    int a = 1;
    int* p = &a;  // pはaのアドレスを保持するポインタオブジェクト
    int &b = *p;  // pの保持するaのアドレスをbに格納(bはaの参照になった)
                  // なぜなら*pでaのアドレスにアクセスしているものを参照したため
    b = 2;        // つまりbはaの参照なので
    cout << a << endl;     // 出力は2
  }

  return 0;
}
