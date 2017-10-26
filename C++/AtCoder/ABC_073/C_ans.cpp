#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  int A[1000001];

  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  sort(A, A+N);

  int temp = A[0];
  int res = 1, count = 0;
  for (int i = 1; i < N; i++) {
    if (temp == A[i]) {  // res = 1からスタート偶数個なら消す
      res++;
      res = res % 2;
    }
    else {
      temp = A[i];
      count += res;
      res = 1;
    }
  }
  count += res;

  printf("%d\n", count);

  return 0;
}
