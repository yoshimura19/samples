#include <iostream>
#include <unorderd_map>
using namespace std;

/* ***
それに対し、unordered_map クラスは O(1) で、さらに高速である。これは、unordered_map が ハッシュテーブル で実装されているからだ。
ただし、unordered_map はその名前の通り、要素を順序付けできない.
* ***/

int main()
{
  unorderd_map<double, int> mp;   // だいたいの型で（ノードのハッシュ値を計算可能で）使用出来る.

  // あとは大体mapとおなじ。

  /* ***
               unordered_map               map
     サポート       C++11                  C++
     データ構造     ハッシュテーブル       二分木（通常は赤黒木）
     登録・削除・検索時間 O(1)             O(log N)
     キー型の制約 hash() が定義済みであること。
                  または、ハッシュ関数オブジェクトを渡す operator<() が定義済みであること。
                  または、自分で定義する
     長短所      ◎ 高速                   ◎ キーが順序づけされる
                 △ キーが順序付けされない △ unordered_map ほどは高速でない
  *** */


  return 0;
}
