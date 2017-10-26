#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main()
{
  int N;  // 3桁の整数
  cin >> N;
  assert(100 <= N && N <= 999);

  string integer = to_string(N);

  // string integer;
  // cin >> integer;

  for (int i = 0; i < integer.size(); i++) { // 入力では必ずサイズ3
    if (integer[i] != integer[2-i]) {
      cout << "No" << endl;
      break;
    }
    if (i == 2) cout << "Yes" << endl;
  }

  return 0;
}
