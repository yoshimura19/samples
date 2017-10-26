#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> l(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }

  sort(l.begin(), l.end());
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans += l[n - 1 - i];
  }
  cout << ans << endl;
}
