#include <iostream>
using namespace std;

// 構造体型Carの宣言
struct Car{
  int num;
  double gas;
};

int main()
{
  Car car1;
  Car car2 = {1234, 25.5};

  cout << "Input the number.:\n";
  cin >> car1.num;

  cout << "Input the quantity of gas that you want.:\n";
  cin >> car1.gas;

  cout << "Number is " << car1.num << ".\nGas is " << car1.gas << ".\n";
  //cout << "Test" << car2;   //couldn't

  return 0;
}
