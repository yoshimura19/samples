#include <iostream>
using namespace std;

// 自分の解答ではBobが先にボタンを押す可能性を忘れていた

int main(void) {
  int A, B, C, D;

  /* Alice (0 <= A < B <= 100), Bob (0 <= C < D <= 100) */

  int const lower = max(A, C);
  int const upper = min(B, D);

  cout << max(0, upper-lower) << endl;

  return 0;
}
