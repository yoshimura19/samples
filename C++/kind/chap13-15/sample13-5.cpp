#include <iostream>
using namespace std;

//Carクラスの宣言
class Car{
private:
  int num;
  double gas;
public:
  //  Car();
  Car(int n=0, double g=0);
  void show();
};

//Carクラスメンバの定義(コントラクタの定義)
// Car::Car()
// {
//   num = 0;
//   gas = 0.0;
//   cout << "車を作成しました。\n";
// }
Car::Car(int n, double g)
{
  num = n;
  gas = g;
  cout << "ナンバー" << num << "ガソリン量" << gas << "の車を作成しました。\n";
}
void Car::show()
{
  cout << "車のナンバーは" << num << "です。\n";
  cout << "ガソリン量は" << gas << "です。\n";
}

int main()
{
  Car mycars[3] = {
    Car(),
    Car(1235,25.5),
    Car(4567,52.2)
  };

  Car yourcars[3];

  return 0;
}
