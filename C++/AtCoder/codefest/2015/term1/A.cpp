#include<iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;

  s[s.size() - 1] = '5';

  cout << s << endl;
}
