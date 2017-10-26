#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;   // K is y location of type B

  vector<int> x(N);   // 0 < x_i < K;
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    assert(0 < x[i] && x[i] < K);
  }

  int d_sum = 0;     // sum of distance
  int B_dist;        // x_i's distance from B
  for (int i = 0; i < N; i++) {
    B_dist = abs(x[i] - K);
    if (x[i] > B_dist) d_sum += 2 * B_dist;
    else d_sum += 2 * x[i];
  }

  cout << d_sum << endl;

  return 0;
}
