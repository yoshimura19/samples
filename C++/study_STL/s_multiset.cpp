#include <iostream>
#include <set>   // multisetではなくsetであることに注意
using namespace std;

int main()
{
  multiset<int> st1{3, 1, 4];  // だいたい他と同じ

  /* *** 値の参照 *** */
  // multisetの内部構造は配列ではなく、二分木になっているので[]演算子は不可
  auto itr = st.begin();
  cout << *itr << "\n";

  // multisetのイテレータはランダム・アクセス不可で、前後のみ移動出来る

  /* *** データの追加 *** */
  st.insert(2); // 値2を追加
  st.insert(3); // multisetは重複を許すので重複してても、値3が追加

  return 0;
}
