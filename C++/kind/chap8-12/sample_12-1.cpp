#include <iostream>
using namespace std;

//Carクラスの宣言
class Car{
public:
  int num;
  double gas;
  void show();
};

void Car::show()
{
  cout << "車のナンバは" << num << "です。\n";
  cout << "ガソリン量は" << gas << "です。\n";
}

int main()
{
  Car car1;

  car1.num = 1234;
  car1.gas = 20.5;

  car1.show();


  //オブジェクトの動的な作成
  Car* pCar;

  pCar = new Car;
  pCar->num =4312;
  pCar->gas =20.5;

  delete pCar;

  return 0;
}


