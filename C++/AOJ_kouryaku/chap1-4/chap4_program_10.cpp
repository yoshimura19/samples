#include <iostream>
#include <vector>
using namespace std;

void print(vector<double> V) {
  for (int i = 0; i < V.size(); i++ ){
    cout << V[i] << " ";
  }
  cout << endl;
}

// vectorは可変長配列として用いることが出来る便利なデータ構造だが、
// 要素数がnのvectorに対する特定の位置へのデータ挿入や削除にはO(n)のアルゴリズムが用いられるのに注意

int main() {
  vector<double> V;

  V.push_back(0.1);
  V.push_back(0.2);
  V.push_back(0.3);
  V[2] = 0.4;
  print(V);

  V.insert(V.begin() + 2, 0.8);  // ベクタの先頭を指すイテレータを返す
  print(V);

  V.erase(V.begin() + 1);
  print(V);

  V.push_back(0.9);
  print(V);

  return 0;
}
