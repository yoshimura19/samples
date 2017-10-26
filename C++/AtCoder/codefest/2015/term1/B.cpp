#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;

  //int A[N] = {};
  int temp;

  long int sum = 0;
  for (int i = 0; i < N; i++) {
    //cin >> A[i];  // 実際入れる必要はない
    cin >> temp;
    //sum = sum*2 + A[i];
    sum = sum*2 + temp;
  }

  cout << sum << endl;

  return 0;
}
