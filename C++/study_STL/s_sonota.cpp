#include <iostream>
#include <vector>
#include <map>
#include <algorithm>   // for next_permutation
#include <numeric>
using namespace std;

int main()
{
  /* *** C++ 範囲ベース for ループ *** */

  int ar[] = {1, 2, 3, 4, 5, 6, 7};
  //  for (int x : ar) {
  for (auto x : ar) {
    cout << x << ' ';
  } cout << endl;

  vector<string> v = {"vector", "auto", "for文", "は便利", "."};
  for (auto x : v) {
    cout << x << ' ';
  } cout << endl;

  map<string, int> mp;
  mp["abc"] = 1;  mp["bcd"] = 5;  mp["cde"] = 3;  mp["def"] = 2;
  for (auto x : mp) {
    cout << x.first << ":" << x.second << endl;
  }

  // 範囲の値を書き換え
  for (int &x : ar ) {   // ＆を指定しておくと参照変数となり要素の値を書き換える事が出来る
    if (x == 1) x = 123;
    cout << x << ' ';
  } cout << endl;


  /* *** 順列生成 *** */

  int const N = 3;
  vector<int> v1(N);
  iota(v1.begin(), v1.end(), 1);   // vに1, 2, ... Nを設定(#include<numeric>)
  do {
    for (auto x : v1) cout << x << " "; cout << endl;
  } while ( next_permutation(v1.begin(), v1.end()) );  // 次の順列を生成

  // next_permutation()は配列またはコンテナクラスの範囲[first, last)を引数で受け取り、その範囲の要素の次の順列を生成する。生成順序は各順列が昇順

  // prev_permutation は降順に並べた順序で順列を生成する。初期配列は要素を降順に並べておく

  return 0;
}
