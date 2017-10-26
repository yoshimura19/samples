#include <iostream>
#include <vector>

using namespace std;

// Assignment 7

int main()
{
  vector<int> v;     // 可変長配列

  cout << "Input a number >" << flush;
  int x;
  if(!(cin >> x)) {
    cout << "Error" << endl;
    return 1;
  }
  v.push_back(x);

  cout << "More number? >" << flush;
  while(cin >> x) {
    v.push_back(x);
  }

  for(int i = 0; i < v.size(); ++i) {
    cout << (i + 1) << ": " << v[i] << '\n';
  }

  return 0;
}
