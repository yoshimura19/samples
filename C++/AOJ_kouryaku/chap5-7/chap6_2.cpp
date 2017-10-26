#include <cstdio>
using namespace std;

int n, A[50];

// 入力値のMから選んだ要素を引いていく再帰関数(resの右側が選ぶ)
int solve (int i, int m) {
  if ( m == 0 ) return 1;
  if ( i >= n ) return 0;
  int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
  return res;
}

int main() {
  int q, M;

  printf("Input a length of an array.\n");
  scanf("%d", &n);
  printf("Input elements of the array.\n");
  for(int i = 0; i < n; i++) scanf("%d", &A[i]);

  printf("First, Input len of elements, then input numbers that you want to check.\n");
  scanf("%d", &q);
  for(int i = 0; i < q; i++ ) {
    scanf("%d", &M);
    if ( solve(0, M) ) printf("yes\n");
    else printf("no\n");
  }

  return 0;
}
