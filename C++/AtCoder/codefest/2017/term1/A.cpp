#include <iostream>
using namespace std;

int main()
{
  string S;
  cin >> S;

  string Yaki = "YAKI";
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (Yaki[i] == S[i]) count++;
  }

  if (count == 4) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
