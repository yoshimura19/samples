#include <iostream>
#include <set>
using namespace std;

/* *******
データを順不同に順序付集合に追加すると、その値をキーにし自動的にソートして内部に格納してくれるぞ。
つまり、要素が常にソートされた状態の配列のようなもの
vector に入っているデータを単純に検索すると処理速度は O(N) だが、あらかじめ O(N * log N) の時間をかけてデータをソートし、 lower_bound 等の二分探索を行うと O(log N) となる。
なので、データが動的に追加されないような場合は、vector を用いた方がメモリ効率がよく、速度差も無い。
通常は赤黒木
******* */

int main()
{
  /* ******* 宣言・初期化 ******* */
  // set<int> st;  // int型の順序付き集合stの宣言
  set<int> st1{3, 1, 4, 1};  // 格納される時に{1, 3, 4}の順序になる(重複は削除される)


  /* ******* 値の参照 ******* */
  set<int> st{3, 1, 4, 5, 9, 2, 6, 5, 3, 5};
  // setの内部構造は配列でなく、二分木なので[]演算子で指定の要素を取り出すことはできない。
  auto itr = st.begin();   // 最初の要素へのイテレータを取得
  cout << *itr << "\n";
  // remark  setのイテレータはランダムアクセス不可で、前後にのみ移動出来る。
  for (auto x : st) {
    cout << x << "\n";
  }

  /* ******* データの追加 ******* */
  st.insert(2);   // 値はソートされた位置に入るのでpush_backなどはない
  // insert(値)はpair<iterator, book>を返す。最初(first)は挿入した値へのイテレータで、2番目(second)は挿入が実際に行われたかどうか。
  auto r = st.insert(2);
  cout << r.second << "\n";


  /* ******* ノードの削除 ******* */
  // erase(値): リターン値として削除したデータの個数(1 or 0)を返す
  auto c = st.erase(3);
  // erase(イテレータ): iterator  リターン値として削除した要素の次の要素へのイテレータを返す
  for (auto itr = st.begin(); itr != st.end(); ) {
    if ( *itr % 2 == 0) itr = st.erase(itr);
    else ++itr;
  }
  // erase(first, last): iterator  // 範囲指定して複数の要素を一度に削除
  set<int> st3{1, 2, 3, 4, 5, 6};
  auto first = st.find(2);
  auto last = st.find(4);
  st.erase(first, last);   // 要素2,3を削除


  /* ******* データの検索 ******* */
  // find(値):iterator  引数で指定された値を検索しそれへのイテレータを返す
  // 処理時間はO(logN)
  cout << st.count(2) << "\n";  // 要素2の個数(0 or 1)を表示


  return 0;
}
