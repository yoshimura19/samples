#include <cstdio>
#include <iostream>
using namespace std;

int dp[50];

int fib(int n) {
  if (n == 0 || n == 1) return dp[n] = 1;
  if ( dp[n] != -1) return dp[n];    // 更新
  return dp[n] = fib(n - 1) + fib(n - 2);
}

int recursive_fib(int n) {
  if (n == 0 || n == 1) return 1;
  return recursive_fib(n - 2) + recursive_fib(n - 1);
}

int main() {
  int n;
  for (int i = 0; i < 50; i++) dp[i] = -1;

  scanf("%d", &n);
  printf("%d\n", fib(n));


  cin >> n;
  int F[50];
  F[0] = F[1] = 1;
  for (int i = 2; i <= n; i++) F[i] = F[i - 1] + F[i - 2];

  cout << F[n] << endl;


  cout << "recursive fib計算中\n";
  cout << recursive_fib(n) << endl;

  return 0;
}
