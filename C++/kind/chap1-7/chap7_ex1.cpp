#include <iostream>
using namespace std;

int square(int x);
double square(double x);

int main()
{
  int num;
  double num2;

  cout << "Input an integer:\n";
  cin >> num;
  cout << "Squared value of " << num << " is " << square(num) << ".\n";

  cout << "Input an decimal number:\n";
  cin >> num2;
  cout << "Squared value of " << num2 << " is " << square(num2) << ".\n";

  return 0;
}

int square(int x)
{
  int y;
  y = x*x;

  return y;
}

double square(double x)
{
  double y;
  y = x*x;

  return y;
}
