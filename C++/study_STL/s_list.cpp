#include <iostream>
#include <list>
using namespace std;

void print(const list<int> &lst);
void eraseLessThan(list<int> &lst, int limit);
void uniq(list<int> &lst);

/* ***
「双方向リスト」とは、要素を格納するノードが前後のノードへのポインタを持ち、どの位置への挿入・削除でも O(1) と高速に処理できるコンテナクラス.が、N 番目のデータ位置に移動するには先頭、または末尾、または現在位置からポインタをたどる必要があり、 ランダム・アクセスの処理速度が O(N) である。

データ数が少ない場合（通常、数１０個程度）は vector の挿入削除も充分高速で、 扱い易いので、通常は vector を使用することをお薦めする。
* ***/


int main()
{
  /* ******* 宣言・初期化 ******* */

  list<int> lst(10, 5);  // 他もベクトルやらと同じ。

  /* ******* 値の参照、代入 ******* */

  // listにはoperator[](size_t)が定義されていない(ランダムアクセスO(N)なので安易に使わないように)
  auto itr = lst.begin();         // iteratorを使う
  *itr = 9;        // 最初の要素を9に変更
  print(lst);     // 関数に書いた

  /* ******* 要素の追加 ******* */
  lst.push_front(987);  lst.push_back(123);  // 先頭と末尾に追加

  // insert(イテレータ, 値):イテレータ
  for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
    if ( *itr == 3 ) {
      itr = lst.insert(itr, 0);  // 3の前に0を挿入,itrは0を指す
      ++itr;                     // itrを3の一にすすめる
    }
  }
  print(lst);


  /* ******* 要素の削除 ******** */
  lst.pop_front();   lst.pop_back();
  auto it = lst.begin(); ++itr; ++itr;
  lst.erase(itr);        // erase(イテレータ): 任意の位置の要素を削除

  // itrが指していた場所はメモリを管理するヒープ領域に返され、itrが指す先は無効になるので、
  // その後もitrをそのまま使用してはいけない。

  for (auto itr = lst.begin(); itr != lst.end(); ) {
    if( *itr == 1 ) itr = lst.erase(itr);  // 要素を削除し、itrは次の要素を指す
    else ++itr;
  }

  eraseLessThan(lst, 6);
  uniq(lst);


  /* ******* 要素のソートsort ******* */

  // sort(lst.begin(), lst.end())はビルドエラー
  // sort()がlistのメンバ関数として用意されている
  lst.sort();
  print(lst);   // POD(PlainOldData)やstring以外だとoperator<()を定義する必要がある


  /* ******* その他のメンバ関数 ******* */

  // lst.empty(); lst.size(); lst.front(); lst.back();
  // lst.clear(); lst.resize();

  return 0;
}


void print(const list<int> &lst)
{
  for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
    cout << *itr << ' ';
  } cout << "\n";
}

void eraseLessThan(list<int> &lst, int limit)
{
  for (auto itr = lst.begin(); itr != lst.end(); ) {
    if ( *itr < limit ) {
      itr = lst.erase(itr);
    } else {
      ++itr;
    }
  }
}

void uniq(list<int> &lst)
{
  auto itr = lst.begin();
  if (itr == lst.end() ) return;   // lstが空の場合
  int prev = *itr++;     // 代入++で最初の要素は削除されることはない
  while ( itr != lst.end() ) {
    if ( *itr == prev ) {    // 同じ要素が続く場合
      itr = lst.erase(itr);
    } else {
      prev = *itr++;
    }
  }
}

