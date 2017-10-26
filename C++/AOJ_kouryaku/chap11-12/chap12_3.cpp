#include <iostream>
#include <stack>
using namespace std;
static int const N = 100;
static int const WHITE = 0;
static int const GRAY = 1;
static int const BLACK = 2;

int n, M[N][N];
int color[N], d[N], f[N], tt;
int nt[N];

// uに隣接するvを番号順に取得
int next(int u) {
  for (int v = nt[u]; v < n; v++) {
    nt[u] = v + 1;   // (再訪問 復路などで行き先を探す時の開始位置)
    if ( M[u][v]) return v;
  }
  return -1;
}

// スタックを用いた深さ優先探索
void dfs_visit(int r) {
  for ( int i = 0; i < n; i++ ) nt[i] = 0;

  stack<int> S;
  S.push(r);       // 始点をstackに追加
  color[r] = GRAY; // 訪問した(中)
  d[r] = ++tt;     // 発見時刻

  while ( !S.empty() ) {
    int u = S.top();
    int v = next(u);
    if ( v != -1 ) {    // 訪問が完了でない
      if ( color[v] == WHITE ) {
        color[v] = GRAY;
        d[v] = ++tt;
        S.push(v);
      }
    } else {   // 訪問完了
      S.pop();  // 要素を取り出し削除
      color[u] = BLACK;
      f[u] = ++tt;
    }
  }
}

void dfs() {    // 初期化
  for (int i = 0; i < n; i++ ) {
    color[i] = WHITE;
    nt[i] = 0;
  }
  tt = 0;

  // 未訪問のuを始点として深さ優先探索
  for ( int u = 0; u < n; u++ ) {
    if ( color[u] == WHITE ) dfs_visit(u);
  }
  for ( int i = 0; i < n; i++ ) {
    cout << i + 1 << ' ' << d[i] << " " << f[i] << endl;
  }
}


int main() {
  int u, k, v;

  cin >> n;
  for (int i = 0; i < n; i++ ) {
    for (int j = 0; j < n; j++ ) M[i][j] = 0;
  }

  for (int i = 0; i < n; i++ ) {
    cin >> u >> k;   // u:頂点の番号, k:uの出次数
    u--;
    for ( int j = 0; j < k; j++ ) {
      cin >> v;
      v--;
      M[u][v] = 1;   // 隣接行列作成
    }
  }

  dfs();

  return 0;
}
