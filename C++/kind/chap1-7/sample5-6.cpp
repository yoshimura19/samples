#include <iostream>
using namespace std;

int main()
{
  int res;
  char ans;

  cout << "Which course do you choose ?\n";
  cout << "Input an integer. \n";
  cin >> res;

  // if(res == 1)
  //   ans = 'A';
  // else
  //   ans = 'B';

  /* 上のif文と同じ処理
     条件 ? trueのときの式1 : falseのときの式2 */

  ans = (res == 1) ? 'A' : 'B';

  cout << ans << " is the selected course.\n";

  return 0;
}
