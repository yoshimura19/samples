#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int K;
  cin >> K;

  int a[s.size()];  // 文字列は3文字
  for (int i = 0; i < s.size(); i++) {
    a[i] = 26 - (s[i] - 'a');
    cout << a[i] << ' ';
  } cout << endl;

  int count[3];
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'a');
    else if (K >= a[i]) {
      s[i] = 'a';
      K -= a[i];
      //cout << K;
      //cout << s[i] << ' ';
    }
  }
  // 3文字目の操作
  K = K % 26;
  //cout << "a[" << s.size() << "]=" << a[s.size()] << "残りk" << K;
  if (K < a[s.size()-1]) s[s.size()-1] = (char)(s[s.size()-1] + K);
  else s[s.size()-1] = 'a' + (K - 1);


  cout << s << endl;

  return 0;
}
