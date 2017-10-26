#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A, A+N);

  int max = 0, temp = 0, ans;
  for (int i = 0; i < (N - 1); i++) {
    if (A[i+1] == A[i]) temp++;
    if (temp > max) {
      max = temp;
      ans = A[i];
    }
    if (A[i+1] != A[i]) temp = 0;
  }

  if (max >= (N + 1) / 2) cout << ans << endl;
  else cout << '?' << endl;

  return 0;
}
