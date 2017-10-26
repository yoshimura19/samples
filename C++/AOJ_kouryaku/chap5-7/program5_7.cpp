#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int A[14] = {1, 1, 2, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
  int *pos;
  int idx;

  // lower_bound(先頭ポインタ, 末尾, value)
  // Aがvectorの場合はA.begin()とA.end()
  pos = lower_bound(A, A + 14, 3);   // 3をソート中にいれ最初の要素の位置をイテレータで返す
  idx = distance(A, pos);  // 2つのポインタの距離を返す関数
  cout << "A[" << idx << "] = " << *pos << endl;  // A[5] = 4

  pos = lower_bound(A, A + 14, 2);
  idx = distance(A, pos);
  cout << "A[" << idx << "] = " << *pos << endl;  // A[2] = 2

  return 0;
}

