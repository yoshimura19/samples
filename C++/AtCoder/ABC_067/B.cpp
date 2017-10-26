#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// B - Snake Toy

void print(vector<int> v) {
  vector<int>::iterator it;
  for ( it = v.begin(); it != v.end(); it++ ) {
    cout << *it << ' ';
  }
  cout << endl;
}

int length(vector<int> v, int K) {
  int i = 0, length = 0;
  vector<int>::iterator it;
  for ( it = v.begin(); it != v.end(); it++ ) {
    i++;
    length += *it;
    if(i == K) break;
  }
  return length;
}

int main()
{
  vector<int> v;
  int N, K;

  cin >> N >> K;
  int x;
  for (int i = 0; i < N; i++) {
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end(), greater<int>());
  cout << length(v, K) << endl;

  //print(v);

  return 0;
}
