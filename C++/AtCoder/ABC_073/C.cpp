#include <iostream>
//#include <vector>
#include <list>
using namespace std;

// 配列でA_iの範囲10^9分0にしておいて、でたA_iだけ加減するのもアリ？
// 以下では連結リストにする

int main()
{
  int N;
  cin >> N;

  int A_i, flag;
  list<int> A;
  list<int>::iterator it;
  for (int i = 0; i < N; i++) {
    cin >> A_i;
    flag = 1;
    for (it = A.begin(); it != A.end(); it++) {
      if (A_i == *it) {
        A.erase(it);
        flag = 0;
        break;
      }
    } if (flag == 1) A.push_back(A_i);
  }

  cout << A.size() << endl;

  return 0;
}
