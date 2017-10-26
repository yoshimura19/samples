#include <iostream>
using namespace std;

//Carクラスの宣言
class Car{
private:
  int num;
  double gas;
public:
  static int sum;   //静的データメンバ
  Car();
  void setCar(int n, double g);
  void show();
  static void showSum();
};

//Carクラスメンバ関数の定義
Car::Car()
{
  num = 0;
  gas = 0.0;
  sum++;                 //コンストラクタが呼び出されたときに静的メンバsumを増やす
  cout << "車を作成しました。\n";
}
void Car::setCar(int n, double g)
{
  num = n;
  gas = g;
  cout << "ナンバーを" << num << "にガソリン量を" << gas << "にしました。\n";
}
void Car::showSum()     //静的データメンバ関数の定義
{
  cout << "車は全部で" << sum << "台あります。\n";
}
void Car::show()
{
  cout << "車のナンバーは" << num << "です。\n";
  cout << "ガソリン量は" << gas << "です。\n";
}

int Car::sum = 0;      //静的データメンバを初期化

//Carクラスの利用
int main()
{
  Car::showSum();      //オブジェクトが作成されていなくても呼び出せる。

  Car car1;
  car1.setCar(1234, 20.5);

  Car::showSum();

  Car car2;
  car2.setCar(4567, 30.5);

  Car::showSum();

  return 0;
}

