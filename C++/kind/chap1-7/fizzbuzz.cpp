#include <iostream>
using namespace std;

int main()
{
  int i,n;

  cout << "Fizz Buzz program\n";
  cout << "Input the last number\n";
  cin >> n;
  cout << '\n';

  for(i = 1; i <= n; i++){
    if(i % 3 == 0 && i % 5 == 0){
      cout << "Fizz Buzz\n";
    }
    else if(i % 3 == 0){
      cout << "Fizz\n";
    }
    else if(i % 5 == 0){
      cout << "Buzz\n";
    }
    else {
      cout << i << '\n';
    }
  }

  return 0;
}
