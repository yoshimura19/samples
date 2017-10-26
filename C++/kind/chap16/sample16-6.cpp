#include <iostream>
using namespace std;

int main()
{
  cout.self(ios::left, ios::adjustfield);
  for (int i=0; i<5; i++){
    cout.width(5);
    cout.fill('-');
    cout << i;
  }

  cout << '\n';
  cout.unsetf(ios::right, ios::adjustfield);
  for (int j=0; j<=5; j++){
    cout.width(5);
    cout.fill('-');
    cout << j;
  }
  cout << '\n';

  return 0;
}
