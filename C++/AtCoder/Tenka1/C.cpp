#include <iostream>
#include <set>
using namespace std;

int const MAX = 10;

int main()
{
  // 多分無理だけど全探索
  int N;
  cin >> N;

  set<double> st;

  int h, n, w;
  for (int h = 1; h <= MAX; h++) {
    for (int n = 1; n <= MAX; n++) {
      for (int w = 1; w <= MAX; n++) {
        cout << double(1/double(h) + 1/double(n) + 1/double(w)) << endl;
        st.insert(1/double(h) + 1/double(n) + 1/double(w));
      }
    }
  }

  for (auto it = st.begin(); it != st.end(); it++) {
    cout << *it << ' ';
  } cout << endl;

  return 0;
}
