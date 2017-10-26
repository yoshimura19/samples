#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  //sort(A.begin(), A.end(), greater<int>());
  sort(A.begin(), A.end());

  int sizes[2] = {}; // sides of rectangle
  int j = 0;         // length1 * length2
  for (int i = 0; i < N; i++) {
    if(j >= 2) break;
    if(A[N - i - 1] == A[N - i - 2]) {
      sizes[j] = A[N - i - 1];
      i++;
      j++;
    }
  }

  cout << sizes[0] * sizes[1] << endl;

  return 0;
}
