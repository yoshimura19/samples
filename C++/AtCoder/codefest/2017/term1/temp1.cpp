#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int a[s.size()];
  for (int i = 0; i < s.size(); i++) {
    a[i] = s[i] - 'a';
  }

  sort(a, a+s.size());

  for (int i = 0; i < s.size(); i++) {
    cout << a[i] << ' ';
  } cout << endl;

  return 0;
}
