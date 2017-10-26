#include <cstdio>

// 線形探索(番兵)
int search(int A[], int n, int key);

int main()
{
  printf("入力形式:\n配列要素数n\n");
  printf("配列\n探すkeyの数\nkeyの入力\n");


  int A[10000 + 1];

  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &A[i]);

  int q;
  scanf("%d", &q);   // q個の探索したいkey

  int key;
  int sum = 0;
  for(int i = 0; i < q; i++) {
    scanf("%d", &key);
    if (search(A, n, key)) sum++;  // key見つかったらif(1)でカウント
  }
  printf("%d\n", sum);  // 探したキーq個中見つかった数を出力

  return 0;
}

int search(int A[], int n, int key){
  int i = 0;
  A[n] = key;        // 番兵の設置
  while(A[i] != key) i++;
  return i != n;
}
