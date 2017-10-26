#include <iostream>
using namespace std;

struct Car{
  int num;
  double gas;
};

void show(Car* pC);

int main()
{
  Car car1 = {0, 0.0};

  cout << "Input the number.:\n";
  cin >> car1.num;

  cout << "Input the gas quantity.:\n";
  cin >> car1.gas;

  show(&car1);   //car1のアドレスを渡す

  return 0;
}

void show(Car* pC)
{
  cout << "Number is " << pC->num << ".\nGas quantity is " << pC->gas << ".\n";
}
