#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// C - Suger Water
// ビーカーの容量が 100A <= F <= 3000で小さいので全探索することにする

// ミスし過ぎたのでやめた

struct condition {
  int w_sum_o;
  int s_sum_o;
  double concentration;
};

int main()
{
  int A, B, C, D, E, F;
  /* A,B ビーカーに入れる水の倍数
     C,D 入れる砂糖の倍数
     E : 100gあたり溶ける最大砂糖(g)
     F : ビーカーの容量
  */

  cin >> A >> B >> C >> D >> E >> F;

  int i = 0, j = 0;
  int s = 0, t = 0;
  int w_sum = 0, s_sum = 0; // 水、砂糖の量
  condition X = {0, 0, 0}; double temp = 0;

  for (int i = 0; 100 * A * i + s_sum <= F; ++i) {
    for (int j = 0; 100*(A*i+B*j) + s_sum <= F; ++j) {
      w_sum = 100 * (A * i + B * j);
      // cout << "水= " << w_sum;
      if (w_sum == 0) break;
      for (int s = 0; C*s < E * (w_sum / 100); s++) {
        for (int t = 0; C*s+D*t < E * (w_sum / 100); t++) {
          s_sum = C * s + D * t;
          // cout << " 砂糖= " << s_sum;
          if (s_sum > E * (w_sum / 100) || w_sum + s_sum > F) break;
          temp = (double)(s_sum) / (w_sum + s_sum);
          // cout << " 濃度= " << temp << endl;
          if (temp >= X.concentration) {
            X.w_sum_o = w_sum;
            X.s_sum_o = s_sum;
            X.concentration = temp;
          }
        }
      }
    }
  }

  cout << X.w_sum_o + X.s_sum_o << " " << X.s_sum_o << endl;

  return 0;
}
