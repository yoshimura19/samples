#include <iostream>
#include <vector>
#include <cassert>

/* 入力例
3 2
1 2
2 3
*/


using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<bool> vis(n+1, false);
  bool ans = false;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    assert(1 <= a && a < b && b <= n);
    if (a == 1) {
      if (vis[b]) {
        ans = true;
      }
      vis[b] = true;
    } else if (b == n) {
      if (vis[a]) {
        ans = true;
      }
      vis[a] = true;
    }
  }

  if (!ans) cout << "IMPOSSIBLE" << endl;
  else cout << "POSSIBLE" << endl;

  return 0;
}
