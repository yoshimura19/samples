#include <iostream>
using namespace std;

int main()
{
  int A, B, C, D;

  cin >> A >> B >> C >> D;
  // assert(0 <= A < B <= 100)略
  // assert(0 <= C < D <= 100)略

  if (B <= C) cout << 0 << endl;
  else {
    if (B <= D) cout << B - C << endl;
    else cout << D - C << endl;
  }

  return 0;
}
