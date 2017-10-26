#include <iostream>
#include <vector>
using namespace std;

// イテレータの例

void print(vector<int> v){
  vector<int>::iterator it;
  // イテレータはSTLのコンテナの要素に対して反復処理を行うためのオブジェクト
  int i = 0;
  for (it = v.begin(); it != v.end(); it++ ){
    if(i++) cout << " ";
    cout << *it;
  }
  cout << endl;
}

int main() {
  const int N = 4;
  vector<int> v;

  for (int i = 0; i < N; i++ ){
    int x;
    cin >> x;
    v.push_back(x);  // ベクタの最後に要素を追加
  }

  print(v);

  // 配列の要素に対しては通常のポインタの用に扱う
  vector<int>::iterator it = v.begin();
  *it = 3;   // 先頭の要素v[0]を3にする
  it++;    // 1つ前に進める
  (*it)++;  // v[1]の要素に1加算する

  print(v);

  return 0;
}


