#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;

  string s0 = "CODEFESTIVAL2016";

  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s0[i] != s[i]) count++;
  }

  cout << count << endl;

  return 0;
}
