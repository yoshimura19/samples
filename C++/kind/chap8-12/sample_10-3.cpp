#include <iostream>
using namespace std;

int main()
{
  int* pA;
  pA = new int;   //メモリの確保

  cout << "動的にメモリを確保しました\n";

  *pA = 10;

  cout << "動的に確保したメモリを使って" << *pA << "を出力しています。\n";

  delete pA;

  cout << "確保したメモリを解放しました。\n";

  return 0;
}
