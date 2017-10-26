#include <iostream>
using namespace std;

int const MAX = 100005;
int const NIL = -1;

struct Node {int p, l, r; }; // 左子右兄弟表現(parent,left,right)

Node T[MAX];
int n, D[MAX];

void print(int u) {
  int c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ", ";
  cout << "depth = " << D[u] << ", ";

  if ( T[u].p == NIL ) cout << "root, ";
  else if ( T[u].l == NIL ) cout << "leaf, ";
  else cout << "internal node, ";


  // 子のリストを配列っぽく出力
  cout << "[";
  for (int i = 0, c = T[u].l; c != NIL; i++, c = T[c].r ){
    if (i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

// 再帰的に深さを求める
void rec(int u, int p) {
  D[u] = p;       // D[u] uの深さを保存。D[]はグローバル変数なのでok
  if ( T[u].r != NIL ) rec(T[u].r, p); // 右の兄弟に同じ深さを設定
  if ( T[u].l != NIL ) rec(T[u].l, p + 1); // 最も左の子に自分の深さ+1を設定
}

int main() {
  int d, v, c, l, r;
  cin >> n;         // 節点の個数,NILで初期化
  for (int i = 0; i < n; i++) T[i].p = T[i].l = T[i].r = NIL;

  for (int i = 0; i < n; i++) {
    cin >> v >> d;      // 自身の節点番号, 次数
    for (int j = 0; j < d; j++) {
      cin >> c;         // 次数分の子の節点番号
      if (j == 0) T[v].l = c;
      else T[l].r =c;
      l = c;
      T[c].p = v;       // 親の設定
    }
  }
  for (int i = 0; i < n; i++) {
    if (T[i].p == NIL) r = i;   // 親の特定, 親の節点番号を記憶
  }

  rec(r, 0);

  for (int i = 0; i < n; i++) print(i);

  return 0;
}
