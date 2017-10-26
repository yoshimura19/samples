#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  // 入力
  int N;                // 問題案
  cin >> N;
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    cin >> D[i];
  }

  int M;        // 問題セット
  cin >> M;
  vector<int> T(M);
  for (int i = 0; i < M; i++) {
    cin >> T[i];
  }

  // 並び替え
  sort(D.begin(), D.end());
  sort(T.begin(), T.end());

  int j = 0; // 問題案カウンタ
  int count = 0; // i = Mまでいけば全問ある
  for (int i = 0; i < M; i++) {
    if (D[j] < T[i]) {while (D[j] < T[i] && j < D.size()) j++;}
    if (D[j] == T[i]) {
      count++;
      j++;
    }
    else if (D[j] > T[i]) break;
  }

  if (count == M) cout << "YES" << endl;
  else cout <<  "NO" << endl;

  return 0;
}
