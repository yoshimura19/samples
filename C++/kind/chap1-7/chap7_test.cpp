#include <iostream>
using namespace std;

//関数テンプレート
template <class T>
T maxt(T x, T y)
{
  if(x > y)
    return x;
  else
    return y;
}

//main関数
int main()
{
  int a, b;
  double da, db;

  cout << "Input two integers:\n";
  cin >> a >> b;

  cout << "Input two decimal numbers:\n";
  cin >> da >> db;

  int ans1 = maxt(a, b);
  double ans2 = maxt(da, db);

  cout << "The max of integers is " << ans1 << ".\n";
  cout << "The max of decimal numbers is " << ans2 << ".\n";

  return 0;
}
