#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;

  // string s1 = s.substr(0, 4);
  // string s2 = s.substr(4, 8);
  // cout << s1 << ' ' << s2 << endl;

  // s.insert(4, " ");
  // cout << s << endl;

  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
    if (i == 3) cout << ' ';
  }
  cout << endl;

  return 0;
}
