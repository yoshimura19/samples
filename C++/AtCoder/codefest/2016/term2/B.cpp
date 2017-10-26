#include <iostream>
using namespace std;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;

  string S;
  cin >> S;

  int dome_st = 0, fori_st = 0, sum = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'a') {
      if (sum < A+B) {
        dome_st++;
        cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    else if (S[i] == 'b') {
      if (sum < A+B && fori_st < B) {
        fori_st++;
        cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    else cout << "No" << endl;   // if(S[i] == c)
    sum = dome_st + fori_st;
  }

  return 0;
}
