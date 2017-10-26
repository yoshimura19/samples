#include <iostream>
using namespace std;

int factorial(int n) {
  if(n == 1) return 1;
  return n * factorial(n - 1);
}
int findMaximum(int A[], int l, int r){
  int m = (l + r) / 2;   // Divide
  if (l == r - 1) return A[l];     // 要素数が1つ
  else {
    int u = findMaximum(A, l, m);  // 前半の部分問題をsolve
    int v = findMaximum(A, m, r);  // 後半の部分問題をsolve
    int x = max(u, v);  // Conquer
    return x;
  }
}

int main()
{
  cout << "階乗を求めます。整数nを入力してください\n";
  int n;
  cin >> n;
  cout << factorial(n) << endl;

  cout << "Input a length of a array first, then input elements of the array.\n";
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < n; i++ ){
    cin >> A[i];
  }

  cout << findMaximum(A, 0, N-1) << endl;

  return 0;
}
