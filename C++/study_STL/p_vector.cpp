#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  /* *** 宣言・初期化 *** */

  vector<char> str;
  vector<double> pos(3);  // 0で初期化
  vector<char> a(10, 'a');

  for (int i = 0; i < pos.size(); i++) {
    cout << pos[i] << ' ';
  } cout << endl;

  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << ' ';
  } cout << endl;

  vector<double> d{1.1, 2.2, 3.3, 4.4};

  vector<int> v1(5);  // 要素5個
  vector<int> v2{5};  // 要素1個で5
  vector<int> v3[5];  // ?? 要素数0のvector * 5個の配列

  //  int array[] = {1, 2, 3, 4, 5};
  // v3.push_back(array);  // error


  /* *** vectorへの代入 *** */
  vector<int> v(10);
  for (int i = 0; i < v.size(); ++i) {
    v[i] = rand() % 100;
  }
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << ' ';
  } cout << endl;

  cout << "v[20]=" << v[20] << endl;
  int v_ar[10];
  cout << "v_ar[20]=" << v_ar[20] << endl;

  vector< vector<int> > vv{{1, 5}, {4, 3}, {2, 1}};
  sort(vv.begin(), vv.end());   // 行の先頭の要素(行)で並び替え
  //sort(vv[1].begin(), vv[1].end());  // 2行目内の並び替え
  for (int i = 0; i < vv.size(); i++) {
    cout << vv[i][1] << ' ';
  } cout << endl;

  return 0;
}
