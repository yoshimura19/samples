#include <iostream>
#include <set>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  int K;
  cin >> K;

  int flag = 0;

  if (K % N == 0) {cout << "Yes" << endl; flag = 1;}
  if (K % M == 0 && flag == 0) {cout << "No" << endl; flag = 1;}
  if (K < N && K < M && flag == 0) {cout << "No" << endl; flag = 1;}

  if (flag == 0) {
    set<int> s;
    int a = 0;

    for (int i = 0; i < (M - 1); i++) {
      a = N * (i + 1);
      for (int j = 0; j < N; j++) {
        a = a + (M - (i + 1)*2);
        s.insert(a);
      }
    }

    int s_before = s.size();
    s.insert(K);
    if (s_before == s.size()) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
