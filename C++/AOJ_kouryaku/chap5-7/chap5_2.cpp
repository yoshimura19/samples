#include <cstdio>

int A[1000000], n;

// 二分探索
int binarySearch(int key);

int main() {

  // int n;    // ここで宣言するとグローバル変数と異なるローカル変数が作られてしまう。
  scanf("%d", &n);
  for(int i = 0; i < n; i++ ){
    scanf("%d", &A[i]);
  }

  int q;
  int k;
  scanf("%d", &q);
  int sum = 0;
  for (int i = 0; i < q; i++ ){
    scanf("%d", &k);
    if ( binarySearch( k ) ) sum++;
  }
  printf("%d\n", sum);

  return 0;
}

int binarySearch(int key) {
  int left = 0;
  int right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    if( A[mid] == key ) return 1;  // keyを発見(main関数のsumで数える)
    else if( A[mid] < key) left = mid + 1;
    else right = mid;   // else if( key < A[mid]) right = mid;
  }
  return 0;
}
