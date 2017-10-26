#include <iostream>
using namespace std;

int square(int x);
double square(double x);

//関数テンプレート
template <class T>
T square(T x){
  //T y;
  //y = x * x;
  return x * x;
}

int main()
{
  int num;
  double num2;

  cout << "Input an integer:\n";
  cin >> num;
  int ans1 = square(num);
  cout << "Squared value of " << num << " is " << ans1 << ".\n";

  cout << "Input an decimal number:\n";
  cin >> num2;
  double ans2 = square(num2);
  cout << "Squared value of " << num2 << " is " << ans2 << ".\n";

  return 0;
}


// int square(int x)
// {
//   int y;
//   y = x*x;

//   return y;
// }

// double square(double x)
// {
//   double y;
//   y = x*x;

//   return y;
// }
