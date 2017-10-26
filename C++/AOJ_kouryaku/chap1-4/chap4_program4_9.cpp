#include <iostream>
#include <queue>
#include <string>
//#include <algorithm>  // たぶんmin関数 (あとでcheck)
using namespace std;

// ALDS1_3_B: Queue p87のライブラリを使った実装

int main() {
  int n, q, t;
  string name;

  queue<pair<string, int> > Q;  //pairは値の悔いをオゾンするための構造体テンプレート

  cin >> n >> q;

  for( int i = 0; i < n; i++ ) {
    cin >> name >> t;
    Q.push(make_pair(name, t));
  }
  // pairはmake_pairによって組を生成し、1つ目の要素はfirst,2つ目はsecondでアクセスすることができる。

  // シミュレーション
  pair<string, int> u;
  int elaps = 0, a;

  while( !Q.empty() ){
    u = Q.front(); Q.pop();
    a = min(u.second, q);  // qまたは必要な時間u.tだけ処理を行う
    u.second -= a;
    elaps += a;
    if (u.second > 0) {
      Q.push(u);  // 処理が完了していなければキューに追加
    } else {
      cout << u.first << " " << elaps << endl;
    }
  }

  return 0;
}
