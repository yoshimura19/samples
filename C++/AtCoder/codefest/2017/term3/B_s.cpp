#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int A[10];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int all = pow(3, N);
  // 似ている数列の数は3^N これから、全部奇数となるものを引く
  // もとが偶数→奇数(+1,-1)の2通り. よって、偶数の個数^2(たぶん)

  int count = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] % 2 == 0) count++;
  }
  //  cout << count << endl;

  int count_even_number = pow(2, count);
  cout << all - count_even_number << endl;

  return 0;
}
