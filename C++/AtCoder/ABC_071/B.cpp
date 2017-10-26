#include <iostream>
using namespace std;

int main()
{
  string S;
  cin >> S;

  bool alp[26];
  for (int i = 0; i < 26; i++) {
    alp[i] = false;
  }
  for (int i = 0; i < S.size(); i++) {
    alp[S[i] - 'a'] = true;
  }
  for (int i = 0; i < 26; i++) {
    if (!alp[i]) {
      cout << (char)(i + 'a') << endl;
      return 0;
    }
  }

  cout << "None" << endl;
  return 0;
}
