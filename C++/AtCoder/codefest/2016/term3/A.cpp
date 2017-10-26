#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int flag = 0;
  for (int i = 0; i < s.size(); i++) {
    if(s[i] == 'C') flag = 1;
    if(flag == 1 && s[i] == 'F') {
      flag = 2;
      break;
    }
  }

  if (flag == 2) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
