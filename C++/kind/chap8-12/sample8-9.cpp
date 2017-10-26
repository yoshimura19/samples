#include <iostream>
using namespace std;

//swap関数のプロトタイプ宣言
void swap(int& x, int& y);  //参照渡し 

int main()
{
  int num1 = 5;
  int num2 = 10;

  cout << "The value of num1 is " << num1 << ".\n";
  cout << "The value of num2 is " << num2 << ".\n";
  cout << "Exchange the value of num1 and num2\n";

  swap(num1, num2);

  cout << "The value of num1 is " << num1 << ".\n";
  cout << "The value of num2 is " << num2 << ".\n";

  return 0;
}

void swap(int& x, int& y)
{
  int temp;
  temp = x;
  x = y;
  y = temp;
}
