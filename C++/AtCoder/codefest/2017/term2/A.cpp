#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;
  string fes = "FESTIVAL";

  //  for (int i = 0; i < fes.size(); i++ ) {
  for (int i = 0; i < s.size() - fes.size(); i++) {
    cout << s[i];
  } cout << endl;

  return 0;
}
