#include <iostream>
#include <map>
using namespace std;

int main()
{
  int N;
  cin >> N;

  map<int, int> mp;
  int A, B;
  for (int i = 0; i < N; i++) {
    cin >> A >> B;
    mp[A] = B;
  }

  // for (auto it = mp.begin(); it != mp.end(); it++) {
  //   cout << it->first << ":" << it->second << endl;
  // }

  auto it = mp.end(); it--;
  //cout << it->first << ":" << it->second << endl;
  cout << it->first + it->second << endl;


  return 0;
}
