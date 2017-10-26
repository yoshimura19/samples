#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int count = 0;
  while (s.size() > 1) {  // 1つだけの要素は回文
    if (s[0] == s[s.size() - 1] ) {
      s.pop_back();  // 末尾削除
      s.erase(s.begin());
      }
    else if (s[0] == 'x' && s[s.size() - 1] != 'x') {
      // s.push_back('x');
      s += 'x';
      count++;
    }
    else if (s[0] != 'x' && s[s.size() - 1] == 'x') {
      s = 'x' + s;
      count++;
    }
    else {
      count = -1;
      break;
    }
  }

  cout << count << endl;

  return 0;
}
