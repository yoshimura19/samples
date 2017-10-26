#include <cstdio>

// 線形探索(番兵を用いて高速化)
int search(int A[], int n, int key);

int main() {
  int A[10000 + 1];

  int n;           // 入力数列数
  scanf("%d", &n);
  for(int i = 0; i < n; i++ ) scanf("%d", &A[i]);
  //  for(int i = 0; i < n; i++ ) printf("%d", A[i]);

  int q;           // 検索数列の数
  int key;         // 検索語
  int sum = 0;     // 一致語カウント
  scanf("%d", &q);
  for(int i = 0; i < q; i++ ) {
    scanf("%d", &key);
    if (search(A, n, key)) sum++;
  }

  printf("%d\n", sum);

  return 0;
}

int search(int A[], int n, int key)
{
  int i = 0;
  A[n] = key;
  while( A[i] != key ) i++;
  return i != n;
}
