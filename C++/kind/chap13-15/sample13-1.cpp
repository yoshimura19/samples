#include <iostream>
using namespace std;

//Carクラスの宣言
class Car{
private:
  int num;
  double gas;
public:
  Car();
  void show();
};

//Carクラスメンバの定義(コントラクタの定義)
Car::Car()
{
  num = 0;
  gas = 0.0;
  cout << "車を作成しました。\n";
}
void Car::show()
{
  cout << "車のナンバーは" << num << "です。\n";
  cout << "ガソリン量は" << gas << "です。\n";
}

int main()
{
  Car car1;

  car1.show();

  return 0;
}
