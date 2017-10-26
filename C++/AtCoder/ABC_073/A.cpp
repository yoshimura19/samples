#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int count = 0;
  for (int i = 0; i < s.size(); i++ ) {
    if (s[i] == '9') count += 1;
  }

  if (count == 0) cout << "No" << endl;
  else cout << "Yes" << endl;

  return 0;
}
