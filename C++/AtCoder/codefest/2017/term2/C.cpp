#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
  int N, M;   // 頂点の数N, 辺の数M
  cin >> N >> M;

  vector<int> G[N+1];  // 無効グラフの連結リストを作ってるつもり
  int A, B;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;   // A_i, B_i辺繋ぎ
    G[A].push_back(B);
    G[B].push_back(A);
  }

  // for (int i = 1; i < N+1; i++) {
  //   cout << i << "=";
  //   for (int j = 0; j < G[i].size(); j++) {
  //     cout << G[i][j] << ' ';
  //   } cout << endl;
  // }

  stack<int> st;
  // 長さ３の辺の効率的な追加分からないので全探索しちゃう
  // 長さ3の
  for (int i = 0; i < 3; i++) {
    G[i][j] = temp;
    p

  return 0;
}
