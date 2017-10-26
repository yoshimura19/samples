#include <iostream>
using namespace std;

// 見やすさのため、if文の内容をブロックにいれました。
// (変数のスコープも変わっていないため等価なプログラムです)

// Assignment 6-1 (K&R style)

//void main2()
int main()
{
  int x;
  cin >> x;

  while (0 <= x) {
    if (x % 3 == 0) {
      cout << "Y";
      cout << "X";
      x--;
    }
  }
}

// Assignment 6-2 (BSD/Allman)

void main2()
//int main()       // 実行用
{
  int x;
  cin >> x;

  while(0 <= x)
  {
    if (x % 3 == 0)
    {
      cout << "Y";
      cout << "X";
      x--;
    }
  }
}
