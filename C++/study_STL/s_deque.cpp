#include <iostream>
#include <deque>
using namespace std;

/* ***
dequeはdouble-ended-queue
deque は vector と同じ動的配列クラスで、末尾だけでなく先頭への要素追加・削除も O(1) と高速なクラス。先頭付近での挿入削除処理が多い場合は deque の使用を検討するといい。ただし、vector と違い、deque の要素は連続したアドレスに保存されているとは限らないので、要素のアドレスを取り出して、 それをポインタとして他の関数に渡すと問題が発生することがあるので、要注意だ。
また、先頭付近での挿入削除以外は、vector の方がパフォーマンスに優れるので、先頭付近での挿入削除を頻繁に行わないのであれば vector を使うのがよい。
*** */

int main()
{

  /* ******* 宣言・初期化 ******* */

  deque<int> data(10, 5);   // 他だいたいvectorと同じように宣言、初期化
  int org_data[] = {4, 6, 5};
  deque<int> data1(org_data, end(org_data));  // 元データから両端キューを生成
  deque<int> data2{1, 2, 4};   // おすすめ

  deque<int> org{1, 2, 3};
  deque<int> x(org);         // コピーコンストラクタ


  /* ******* 値の参照、代入 ******* */

  // []演算子を使ってvector同様にアクセス。[]でのランダムアクセスO(1)
  deque<int> dq{3, 4, 19, 20, 31, 11, 1, 4, 1, 5};
  dq.front() = 6; dq.back() = 12; // 最初と最後の要素

  /* ******* データの追加・削除 ******* */

  dq.push_front(123); dq.push_back(123);
  // クラスオブジェクトの場合 dq.emplace_front(), dq.emplace_back()

  dq.pop_front();  dq.pop_back();   // 削除
  dq.erase(dq.begin() + 2);    // 3番目の要素を削除
  dq.erase(dq.begin() + 1, dq.begin() + 3);  // erase(first, last)はO(N)ですむ

  /* ******* イテレータ ******* */
  deque<int>::iterator it;
  for (it = dq.end(); it != dq.begin(); --it) {
    cout << *it << ' ';
  } cout << endl;

  return 0;
}
