#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
  int x, a, b;

  cin >> x >> a >> b;

  int A, B;
  A = abs(x - a);
  B = abs(x - b);
  A < B ? cout << 'A' << endl : cout << 'B' << endl;

  return 0;
}
