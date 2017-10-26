#include <iostream>
using namespace std;

int const MAX = 20000;

int H, A[MAX + 1];   // ヒープサイズ

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

int main() {
  cin >> H;

  for (int i = 1; i <= H; i++) cin >> A[i];

  for (int i = H / 2; i >= 1; i--) maxHeapify(i);

  for (int i = 1; i <= H; i++ ) {
    if (i >= 2) cout << " ";
    cout << A[i];
  }
  cout << endl;

  return 0;
}
