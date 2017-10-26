#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> vt;
  for(int i=0; i<10; i++){
    vt.push_back(i);
  }

  cout << "並べ換え前は";
  vector<int>::iterator it = vt.begin();
  while(it != vt.end()){
    cout << *it;
    it++;
  }
  cout << "です。\n";

  cout << "逆順にすると";
  reverse(vt.begin(), vt.end());
  it = vt.begin();
  while(it != vt.end()){
    cout << *it;
    it++;
  }
  cout << "です。\n";

  cout << "並べ替え後は";
  sort(vt.begin(), vt.end());
  it = vt.begin();
  while(it != vt.end()){
    cout << *it;
    it++;
  }
  cout << "です。\n";

}
