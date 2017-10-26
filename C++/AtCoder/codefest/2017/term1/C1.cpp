#include <iostream>
#include <algorithm>
using namespace std;

// 列の並び換えは配列でつくる
// 行の確認は読み込みと同時

int main()
{
  int H, W;
  cin >> H >> W;

  string s;
  int a[H][W];
  for (int i = 0; i < H; i++) {
    cin >> s;
    for (int j = 0; j < W; j++) {
      a[i][j] = s[j] - 'a';
    }
    sort(a[i][], a[i][] + W);
    int count = 0;
    for (int j = 0; j < W; j++) {
      if (a[i][j+1] == a[i][j]) {
        count++;
  }


  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) {
  //     cout << a[i][j] << ' ';
  //   } cout << endl;
  // }

  return 0;
}
