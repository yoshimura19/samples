#include <iostream>
#include <set>
using namespace std;

int main()
{
  set<int> s{1, 2, 3};
  cout << s.size() << endl;

  s.insert(2);
  cout << s.size() << endl;

  s.insert(4);
  cout << s.size() << endl;


  return 0;
}
