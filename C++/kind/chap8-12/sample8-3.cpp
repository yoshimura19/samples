#include <iostream>
using namespace std;

int main()
{
  int a;
  int* pA;

  a = 5;
  pA = &a;

  cout << "変数aの値は" << a << "です\n";
  cout << "変数aのアドレスは" << &a << "です\n";
  cout << "ポインタpAの値は" << pA << "です\n";
  cout << "*pAの値は" << *pA << "です\n";  //*は間接参照演算子(indirection operator)

  return 0;
}
