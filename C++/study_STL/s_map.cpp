#include <iostream>
#include <map>
using namespace std;

/* ***
mapping(写像)からmapというクラス名,単純な配列を使ってキーから要素を取得する処理時間は O(N) であるが、map は O(log N) と高速である。 これは map クラスが２分木（実装に依るけど、たいていは赤黒木）で実装されているから。
二分探索することになるので探索測度がO(LogN)
map とよく似たクラスとして、C++11で追加された unordered_map というものもある。 これは ハッシュ を使っているために、キーから要素を取り出す処理時間が O(1) とさらに高速である。
ただし、unordered_map はその名前の通り、要素が順序付けされていないという欠点
*** */

bool isContained(const map<string, int> & mp, int val);

int main()
{
  /* ******* 宣言・初期化, 値の設定参照、取得 ******* */
  map<string, int> mp;

  mp["abc"] = 123; mp["abc"] = 456;  // mapのツリーにキーと値のペアが追加される
                                     // 追加処理に要するコストは要素数をNとしてO(LogN)

  cout << mp["abc"] << endl;
  cout << mp["IBM"] << endl;   // mp["IBM"]は設定されていなかったので0を表示

  // []演算子が返す型は（非constな）値への参照、連想配列が保持していないキーを使うと
  // そのキーとデフォルト値のノードが作成されてしまう。
  // なので、 const型の連想配列に対しては[]を使うことは出来ない const map<>

  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    cout << "key = " << itr->first                // キーを表示
         << ", val = " << itr->second << "\n";    // 値を表示
  }

  isContained(mp, 1);   // 自作関数

  // remark  キーは昇順に格納(2分木) stringの場合辞書順


  /* ******* キーの検索 ******* */
  // find(キー): イテレータ
  auto it = mp.find("xyz");   // "xyz"が設定されているか？
  // キーが設定されている場合はそれへのイテレータ、いない場合はend()へのイテレータを返す
  if (it != mp.end()) {
    cout << it->first << ":" << it->second << endl;
  }
  else cout << "null" << endl;

  // lower_bound(キー): iterator, upper_bound(キー): iterator
  // 引数で指定されたキー以上のキーを持つ最初のノードへのイテレータをかえす
  mp["a"] = 1; mp["b"] = 2; mp["x"] = 10; // mp.lower_bound("b")は("b", 2)のペアへのイテレータ
                                          // mp.lower_bounde("z")はend()
                                          // mp.upper_bound(キー)は、引数で指定されたキーより大きいキーをもつ最初のノードへのイテレータ


  /* ******* 要素の削除 ******* */
  // erase(キー), erase(イテレータ)
  mp.erase("abc");   // erase(キー)削除した要素数(0または1)を返す、存在しないキーを指定された場合は無視

  mp.erase(mp.lower_bound("i"), mp.upper_bound("k"));
  // erase(first, last):イテレータ[first, last)の範囲のノードを一度に消す



  return 0;
}

bool isContained(const map<string, int> & mp, int val)
{
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    if( itr -> second == val )     // 値を発見した場合
      return true;
  }
  return false;   // 値が発見出来なかった場合
}
