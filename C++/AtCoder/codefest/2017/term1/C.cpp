#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  string s;
  int a[H*W] = {};

  for (int i = 0; i < H; i++) {
    cin >> s;
    cout << s << endl;
    for (int j = 0; j < W; j++) {
      a[i*(H+1) + j] = s[j] - 'a';
      cout << a[i*(H+1) + j] << ' ';
    } 
  }

  for (int j = 0; j < H*W; j++) {
    cout << a[j] << ' ';
  } cout << endl;

  return 0;
}
