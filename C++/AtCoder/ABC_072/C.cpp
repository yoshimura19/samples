#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> a(N);

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  // 以降数列a[i]は小さい順


  // 探すのはX, X-1, X+1と続いてる個数が最大のもの
  vector<int> sum(N);
  int temp;
  for (int i = 0; i < N; i++) {
    temp = a[i];
    for (int j = 1;;j++) {  // 無限ループ注意
      //cout << "i=" << i << " j=" << j << endl;
      // if (i - j >= 0) {  // 左探索条件
      //   if (temp - 1 <= a[i - j]) sum[i]++;
      // }
      // if (i + j < N) {  // 右探索条件
      //   if (temp + 1 >= a[i + j]) sum[i]++;
      // }
      //cout << "sum[" << i << "]=" << sum[i] << endl;

      if (i - j >= 0 && temp - 1 <= a[i - j]) sum[i]++;
      if (i + j < N && temp + 1 >= a[i + j]) sum[i]++;
      else break;
      if (i - j <= 0 && i + j >= N) break;
    }
  }

  sort(sum.begin(), sum.end());
  cout << sum[N-1]+1 << endl;  // 自分自身を+1

  return 0;
}
