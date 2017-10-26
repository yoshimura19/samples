#include <iostream>
using namespace std;

int main()
{
  long long int X, t;

  cin >> X >> t;
  int res = (X >= t) ? (X - t) : 0;

  cout << res << endl;

  return 0;
}
