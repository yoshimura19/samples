#include <iostream>
using namespace std;

int main()
{
  int res;

  cout << "Input an integer:\n";
  cin >> res;

  if(res == 1){
    cout << "The input is 1.\n";
  }
  else if(res == 2){
    cout << "The input is 2.\n";
  }
  else{
    cout << "Input 1 or 2.\n";
  }

  return 0;
}
