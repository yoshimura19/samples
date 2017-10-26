#include <cstdio>
#include <cstring>
#include <iostream>
//#include <algorithm>
using namespace std;

int const MAX = 2000000;
int const INFTY = (1 << 30);  // ビットを左に30移動(1073741824)

int H, A[MAX + 1];

void maxHeapify(int i) {
  int l, r, largest;
  l = 2 * i;
  r = 2 * i + 1;

  // 左の子、自分、右の子で最大のノードを選ぶ
  if (l <= H && A[l] > A[i] ) largest = l;
  else largest = i;
  if (r <= H && A[r] > A[largest] ) largest = r;

  if (largest != i){
    swap(A[i], A[largest]);
    maxHeapify(largest);   // iが根となる部分木に対し再帰
  }
}

int extract() {
  int maxv;
  if (H < 1) return -INFTY;
  maxv = A[1];
  A[1] = A[H--];   // 根に一番下のを写してHサイズ1減らす
  maxHeapify(1);   // 最大ヒープを保つように
  return maxv;
}

void increaseKey(int i, int key) {
  if (key < A[i]) return;  // A[i]には-INFTYが入っている
  A[i] = key;     // 葉に入れる
  while ( i > 1 && A[i / 2] < A[i] ) { // 葉から一つ上と比較する
    swap(A[i], A[i/2]);
    i = i / 2;
  }
}

void insert(int key) {
  H++;
  A[H] = -INFTY;
  increaseKey(H, key);
}

int main()
{
  int key;
  char com[10];

  while (1) {
    scanf("%s", com);
    if ( com[0] == 'e' && com[1] == 'n') break;  // 命令"end"
    if ( com[0] == 'i' ) {
      scanf("%d", &key);
      insert(key);
    } else {
      printf("%d\n", extract());
    }
  }

  return 0;
}
