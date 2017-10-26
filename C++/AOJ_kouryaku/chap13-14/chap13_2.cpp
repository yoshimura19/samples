#include <iostream>
using namespace std;

static int const MAX = 100;
static int const INFTY = (1<<21);
static int const WHITE = 0;
static int const GRAY = 1;
static int const BLACK = 2;

int n, M[MAX][MAX];

int prim()
{
  int u, minv;
  int d[MAX], p[MAX], color[MAX];  // d[v]重みが最小の辺を記録, p[v]:vの親を記録

  for ( int i = 0; i < n; i++ ) {
    d[i] = INFTY;
    p[i] = -1;
    color[i] = WHITE;
  }

  d[0] = 0;

  while ( 1 ) {
    minv = INFTY;
    u = -1;
    for (int i = 0; i < n; i++ ) {
      if ( minv > d[i] && color[i] != BLACK ) {
        u = i;                   // 一番小さいd[i]を与えるuを選択
        minv = d[i];
      }
    }
    if (u == -1) break;  // 頂点uの選択なし(更新なし)
    color[u] = BLACK;
    for ( int v = 0; v < n; v++ ) {
      if ( color[v] != BLACK && M[u][v] != INFTY ) { // 頂点uから行ける辺(v exist)
        if ( d[v] > M[u][v] ) {  // defaultはINFTY, 訪問で更新
          d[v] = M[u][v];
          p[v] = u;          // vの親をuに
          color[v] = GRAY;
        }
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++ ) {
    if ( p[i] != -1 ) sum += M[i][p[i]];  // i = 0の親はM[0][-1]なのでskip
  }

  return sum;
}

int main()
{
  cin >> n;

  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < n; j++ ) {
      int e; cin >> e;
      M[i][j] = (e == -1) ? INFTY : e;
    }
  }

  cout << prim() << endl;

  return 0;
}
