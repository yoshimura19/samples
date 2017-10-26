#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int N, A[100];

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int flag = 0;  // 自分より前に偶数でたか
  int count = 0;
  int doko = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] % 2 == 1) {          // 自分が奇数なら自分を偶数に変えたら後は何でもok
      count += 2 * pow(3, (N - (i + 1)));
      doko = 0;
    }
    else if (A[i] % 2 == 0 & flag == 0) { // 自分が偶数で今まで偶数なし、(自分は変えない)
      count += pow(3, (N - (i + 1)));
      doko = 1;
    }
    else if (A[i] % 2 == 0 & flag == 1) { // 自分が偶数で今まで偶数あり）
      count += 2 * pow(3, (N - (i + 1)));  // 以降なんでもありなので奇数にかえる
      doko = 2;
    }

    if (A[i] % 2 == 0) flag = 1;
    cout << "i=" << i << "番目目" << "doko=" << doko << " " << count << endl;
  }
  cout << count << endl;

  return 0;
}
