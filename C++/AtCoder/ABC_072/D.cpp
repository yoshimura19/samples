#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> p(N+1);
  // index is 1 originated.
  for (int i = 1; i < N+1; i++) {
    cin >> p[i];
  }

  int count = 0;
  int temp = 0;
  for (int i = 1; i < N; i++) {
    if (p[i] == i) {
      count++;
      temp = p[i];
      p[i] = p[i+1];
      p[i+1] = temp;
    }
  }

  if (p[N] == N) {   // 右端だけ左とスワップ
    count++;
    temp = p[N];
    p[N] = p[N-1];
    p[N-1] = temp;
  }

  cout << count << endl;

  return 0;
}
