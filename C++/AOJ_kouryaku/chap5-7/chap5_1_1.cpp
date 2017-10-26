#include <cstdio>

// 線形探索(番兵を用いる)
int search(int A[], int n, int key);

int main() {
  int A[10000 + 1];

  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++ ) scanf("%d", &A[i]);

  int q;
  scanf("%d", &q);

  int key;
  int sum = 0;
  for(int i = 0; i < q; i++ ) {
    scanf("%d", &key);
    if (search(A, n, key)) sum ++;
  }

  printf("%d\n", sum);

  return 0;
}

int search(int A[], int n, int key)
{
  int i = 0;
  A[n] = key;
  while( A[i] != key){
    i++;
  }
  if(i != n){
    return 1;
  } else {
    return 0;
  }
}
