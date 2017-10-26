#include <cstdio>

int isPrime(int x) {
  int i;
  if (x < 2) return 0;
  else if (x == 2) return 1; /* 2は素数 */
  if (x % 2 == 0) return 0;
  for (i = 3; i*i <= x; i+=2) { /* iがxの平方根以下の間 */
    if (x % i == 0) return 0;
  }
  return 1;
}

void eratos(int n) {
  bool isprime[n];
  isprime[0] = isprime[1] = false;
  for (int i = 2; i < n; i++) {
    isprime[i] = true;
  }
  for (int i = 2; i*i <= n; i++) {
    if (isprime[i]) {
      int j = i + i;
      while (j <= n) {
        isprime[j] = false;
        j = j + i;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if ( isprime[i] ) printf("%d ", i);
    if (i % 30 == 0) printf("\n");
  }
}

int main() {
  int n;
  // scanf("%d", &n);

  // int cnt = 0;
  // int x;
  // for (int i = 0; i < n; i++) {
  //   scanf("%d", &x);
  //   if ( isPrime(x) ) cnt++;
  // }
  // printf("%d\n", cnt);

  int y;
  printf("Do you want to active Sieve of Erasthenes?\nyes:input number, no:0\n");
  scanf("%d", &y);
  // printf("%d\n", y);
  if( y ) eratos(y);

  return 0;
}
