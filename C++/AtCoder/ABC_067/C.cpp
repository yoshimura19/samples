#include <iostream>
#include <cstdlib>
using namespace std;
// C - Splitting Pile

int main ()
{
  int N;
  int X = 0;      // total

  cin >> N;
  int cards[N];
  int sum_xi[N];

  for ( int i = 0; i < N; i++ ) {
    cin >> cards[i];
    X += cards[i];
    sum_xi[i] = X;
  }

  // 全合計をX , sum x_iをx_iの合計  sum y_i = X - sum x_i
  // then, abs(sum x_i - sum y_i) = abs(X - 2 * sum x_i)

  int min = abs(X - 2 * sum_xi[0]);  // adohoc初期値
  int temp;
  for ( int i = 0; i < N - 1; i++ ) { // sum y_iは少なくとも1つ
    temp = abs( X - 2 * sum_xi[i]);
    if ( temp < min ) min = temp;
  }

  cout << min << endl;

  return 0;
}
