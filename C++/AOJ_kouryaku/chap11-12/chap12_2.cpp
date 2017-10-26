#include <iostream>
using namespace std;

static int const N = 100;

int main()
{
  int M[N][N];
  int u, k;   // u頂点の番号, k出次数
  int v;     // 隣接する頂点の番号

  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      M[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    u--;   // 0-オリジンに。
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;   // 0-オリジンに
      M[i][v] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << M[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}

