#include <iostream>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {      // gcd(greatest common divisor)
  if (b == 0) return 0;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {     // lcm(least common multipler)
  ll g = gcd(a, b);     // formula : ab = gcd(a, b) * lcm(a, b)
  return (a * b) / g;   // Be careful not to overflow
}

int main()
{
  int N;
  cin >> N;

  ll ans = 1LL;

  for (int i = 0; i < N; i++) {
    ll T;
    cin >> T;
    ans = lcm(ans, T);
  }

  cout << ans << endl;

  return 0;
}
