#include <iostream>
#include <cmath>
using namespace std;

int const MAX = 3500;

int main()
{
  int N;
  cin >> N;

  int w;
  double numerator, denominator;
  for (int h = 1; h <= MAX; h++) {
    for (int n = 1; n <= MAX; n++) {
      numerator = N * h * n;
      denominator = 4*h*n - n*N - h*N;
      w = numerator / denominator;
      if (ceil(w) == floor(w) && w > 0) {
        cout << h << ' ' << n << ' ' << w << endl;
        return 0;
        //h = MAX + 1;  // 外も抜ける用
        //break;
      }
    }
  }

  return 0;
}
