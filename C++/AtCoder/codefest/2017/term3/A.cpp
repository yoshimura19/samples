#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int flag = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      if (s[i+1] == 'C') {
        flag = 1;
        break;
      }
    }
  }

  if (flag == 1) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
