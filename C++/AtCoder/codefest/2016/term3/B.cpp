#include <iostream>
//#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int K, T;
  cin >> K >> T;

  int a[T];
  for (int i = 0; i < T; i++) {
    cin >> a[i];
  }

  sort(a, a+T);

  // for (int i = 0; i < T; i++) {
  //   cout << a[i] << ' ';
  // } cout << endl;

  int min_day;
  min_day = max(a[T-1] - 1 - (K - a[T-1]),0);

  cout << min_day << endl;

  return 0;
}
