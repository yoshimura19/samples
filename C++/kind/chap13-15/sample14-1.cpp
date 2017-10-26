#include <iostream>
using namespace std;

//Carクラスの宣言
class Car{
private:
  int num;
  double gas;
public:
  Car();
  void setCar(int n, double g);
  void show();
};

//RacingCarクラスの宣言
class RacingCar : public Car{   //派生クラスの宣言
private:
  int course;
public:
  RacingCar();
  void setCourse(int c);
};

//Carクラスメンバ関数の定義
Car::Car()
{
  num = 0;
  gas = 0.0;
  cout << "車を作成しました。\n";
}
void Car::setCar(int n, double g)
{
  num = n;
  gas = g;
  cout << "ナンバーを" << num << "にガソリン量を" << gas << "にしました。\n";
}
void Car::show()
{
  cout << "車のナンバ＝は" << num << "です。\n";
  cout << "ガソリン量は" << gas << "です。\n";
}

//RacingCarクラスメンバ関数の定義
/* 何も指定がないと、基本クラスの引数なしのコンストラクタが最初に呼び出される */
RacingCar::RacingCar()
{
  course = 0;
  cout << "レーショングカーを作成しました。\n";
}
void RacingCar::setCourse(int c)
{
  course = c;
  cout << "コース番号を" << course << "にしました。\n";
}

int main()
{
  RacingCar rccar1;
  rccar1.setCar(1234, 20.5);
  rccar1.setCourse(5);

  return 0;
}
