#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

  /* ******* データの宣言 ******* */

  vector<int> data(123);   // 初期要素数123
  vector<int> data2(10, 5);  // 要素数10,全て値5で初期化

  int org_data[] = {4, 6, 5};  // 元データ
  vector<int> data3(org_data, end(org_data));  // 元データから動的配列を生成

  // コピーコンストラクタ
  vector<int> org{1, 2, 3};
  vector<int> x(org);      // コピーコンストラクタ
                           // orgをコピー

  // 2次元配列
  vector< vector<int> > vv{{1, 2, 3}, {4, 5, 6, 7, 8, 9}}; // 2行1列目3, 2列目6
                // >>は右シフト演算子なのでC++11未満では> >と間に空白が必要
  cout << "vv{{1, 2, 3}, {4, 5, 6, 7, 8, 9}}" << endl;
  cout << "vv.size() = " << vv.size() << endl;
  cout << "vv.front().size() = " << vv.front().size() << endl;
  cout << "vv.back().size() = " << vv.back().size() << endl;
  vv.push_back({10, 11, 12});  // 要素の追加


  for (int i = 0; i < vv.size(); i++) {
    for (int j = 0; j < vv.front().size(); j++) {
      cout << vv[i][j] << ' ';
    } cout << endl;
  }


  /* ******* vectorへの代入 ******* */

  // 現在保持している要素を全て破棄して、新しい要素を代入することができる

  int ar[] = {1, 2, 3, 4, 5, 6, 7};
  vector<int> v{9, 8};
  v.assign(&ar[0], &ar[3]);    // vの内容は{1, 2, 3}になる
  v.assign(3, 1);              // vの内容は{1, 1, 1}

  // イテレータ  // 抽象化されたポインタ
  vector<int>::iterator it;
  vector<int> v2{1, 2, 3, 4};
  for (auto it = v2.begin(); it != v2.end(); ++it) {
    cout << *it << ' ';
  } cout << endl;


  /* ******* データの追加 ******* */
  struct foo{
    int first;
    int second;
    string word;
  };
  vector<foo> h;
  foo a = {3, 2, "evening"}, b = {5, 2, "morning"}, c = {1, 3, "night"};
  h.push_back(a);   h.push_back(b);  h.push_back(c);
  h.push_back({1, 1, "can?"});   // O(1)

  // sort(h.begin(), h.end());  // can not
  cout << h[3].word << endl;

  // emplace_back(コンストラクタ引数):void (クラスで保持)
  //h2.emplace_back(123, "ok?");  // push_back(Hoge("abc", 123))

  vector<int> v3(5, 3);
  v.insert(v.begin() + 2, 7);  // {3, 3, 7, 3, 3, 3} O(N)の処理時間


  /* ******* データの削除 ******* */

  vector<int> v4{3, 1, 4, 1, 5, 6, 7, 7, 1, 2};
  int last = v4.back();   // 末尾データを取り出す
  v4.pop_back();  // 末尾データ削除 O(1) :void
  v4.erase(v4.begin() + 2);  // 3番目の要素を削除 O(N)
  v4.erase(v4.begin() + 1, v4.begin() + 5); // これはO(N)ですむ(M文字のO(N))ではない
  for (int i = 0; i < v4.size(); i++) cout << v4[i] << ' ';
  cout << endl;

  /* ******* その他のメンバ関数 ******* */

  vector<int> v5 = {1, 2, 3, 4, 5};
  // if ( !v.empty() )  // 空かどうか判定 size()==0より高速
  auto f = v5.front(); auto g = v.back();  // 最初、最後の要素
  v5.front() = 11; v5.back() = 44; // back()は要素への参照を返すので代入可
  int *ptr = v5.data();  // 要素の型へのポインタ

  // clear() :void 動的配列を空にする
  // reserve(サイズ) :void   データを大量に追加する場合、あらかじめメモリを確保する(メモリのアロケートとデータコピーが多く呼ばれる場合があるため)
  v5.reserve(10000);
  // for (int i = 0; i < 10000; i++) v.busk_back(i);
  vector<int> z;  // swap(オブジェクト)　内容を入れ替える
  v5.swap(z);


  /* ******* vectorを関数の引数として渡す ******* */
  // int max(const vector<int> &v)  // 参照渡し(変更する場合はconstなし)
  // コピーする必要がある場合はint max(vector<int> v)


  /* ******* アルゴリズム ******* */
  vector<int> v10{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  cout << count(v10.begin(), v10.end(), 5) << endl;  // 要素5の数を返す
  // find 動的配列の最初から最後までを走査し、最初の要素へのイテレータを返します。
  sort(v10.begin() + 3, v10.end() - 5);  // 一部のソート
  reverse(v.begin(), v.end());   // 順序逆転

  return 0;
}
