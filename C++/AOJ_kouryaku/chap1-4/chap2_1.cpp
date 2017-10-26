#include <iostream>
#include <algorithm>

using namespace std;
static const int MAX = 200000;

int main()
{
  int R[MAX], n;

  // First line gives the declation of n data will be readed.
  cin >> n;

  for(int i = 0; i < n; i++) cin >> R[i];

  int maxv = -200000000;   // 十分小さい初期値を設定
  int minv = R[0];

  for (int i = 1; i < n; i++){
    maxv = max(maxv, R[i] - minv);  // 最大値を更新
    minv = min(minv, R[i]);
  }

  cout << maxv << endl;

  return 0;
}
