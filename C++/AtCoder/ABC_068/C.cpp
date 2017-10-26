#include <iostream>
#include <vector>
#include <stack>
using namespace std;

static int const MAX = 200000;
static int const NIL = -1;
int color[MAX] = {};   // WHITE = 0なので初期化ok

int N;
vector<int> I[MAX];   // Island
static int const WHITE = 0;
static int const GRAY = 1;
static int const BLACK = 2;

int next(int u) {
  for (int i = 0; i < I[u].size(); i++ ) {
    if ( color[ I[u][i] ] == WHITE) {
      cout << I[u][i];
      return I[u][i];
    }
  }
  return NIL;     // 全部訪問終了だったらNIL(-1)
}

int dfs(int r) {
  stack<int> S;
  S.push(r);
  color[r] = GRAY;    // 訪問中

  int count = 0;
  while ( !S.empty() ) {
    count += 1;
    if (count == 3) break;  // 定期便を使える回数は2回まで ←見逃してた^^;

    int u = S.top();
    cout << "nextに渡すu" << u << endl;
    int v = next(u);
    if ( v != -1 ) {
      if ( color[v] == WHITE ) {
        color[v] = GRAY;
        S.push(v);
        cout << "今" << v << endl;
        if (v == N) return 1;
      }
      else {
        S.pop();
        color[u] = BLACK;
      }
    }
  }
  return 0;
}

int main()
{
  int a, b, M, q;
                     // stackを用いた深さ優先探索
  cin >> N >> M;    // Mは辺の数, 隣接リストで管理

  for ( int i = 0; i < M; i++ ) {
    cin >> a >> b;
    I[a].push_back(b);
    I[b].push_back(a);
  }

  if ( dfs(1) ) {
    cout << "POSSIBLE" << endl;
  } else cout << "IMPOSSIBLE" << endl;
  


  return 0;
}
