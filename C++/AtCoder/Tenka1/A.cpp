#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  cin >> S;

  int count = 0;
  for (int i = 0; i < 6; i++) {
    if (S[i] == '1') count++;
  }

  cout << count << endl;

  return 0;
}
