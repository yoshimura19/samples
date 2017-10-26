#include <iostream>
#include <map>   // multimapでなくmapであることに注意
using namespace std;

/* ***
同じ連想配列クラスの std::map は、各キーに対する値はひとつだけだが、 この multimap は各キーに対する値を複数持つことができる。そういう意味で「多重連想配列」と呼ばれる。
*** */

int main()
{

  /* ******* 宣言・要素の追加 ******* */
  multimap<string, int> mp;
  mp.insert(make_pair("abc", 123));
  mp.insert(make_pair("abc", 987));
  mp.insert(make_pair("abc", 123));   // 同じキーを持つ要素を再度通過すると値のペアが同じであっても全て追加される(mapだと最後に書き込んだものだけ)


  /* ******* 要素の検索 ******* */
  // find(キー):イテレータ
  // lower_bound(キー):イテレータ, upper_bound(キー):イテレータ
  // equal_range(キー):pair<イテレータ,イテレータ>

  auto itr = mp.find("abc");  // キー:"abc"を検索
  if (itr != mp.end() ) {  // 見つかった場合
    cout << itr->first << " " << itr->second << "\n";
  } else cout << "not found.\n";

  // ower_bound(キー) は、指定されたキー以上のキーを持つ最初のイテレータを返す。それが無い場合は オブジェクト.end() を返す。
  //例えば、キーとして 1, 3, 3, 5 のノードがある場合、lower_bound(3) を実行すると、最初の3以上の値は2番め3なので、それへのイテレータを返す。

  auto r = mp.equal_range("xyz");  // xyzの範囲を取得
  mp.erase(r.first, r.second);   // first, secondに範囲が入っている？


  /* ******* 要素の削除 ******* */
  // erase(キー), erase(イテレータ):イテレータ, erase(first, last):イテレータ
  auto it = mp.find("xyz");
  if (it != mp.end()) {
    mp.erase(itr);      // erase(イテレータ)の処理時間はO(1)
  }

  auto first = mp.lower_bound("xxx");
  auto last = mp.upper_bound("yyy");
  mp.erase(first, last);   // "xxx" ~ "yyy"の範囲を全削除
  

  return 0;
}
