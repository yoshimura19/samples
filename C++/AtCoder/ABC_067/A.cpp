#include <iostream>
using namespace std;

// A - Sharing Cookies

int main()
{
  int A, B;

  cin >> A >> B;

  // A,B,A+Bのいずれかが3で割り切れれば、3匹のヤギは同じ枚数食べられる
  if (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) cout << "Possible" << endl;
  else cout << "Impossible" << endl;

  return 0;
}
