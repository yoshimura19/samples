#include <iostream>
using namespace std;

//クラスの宣言

class Point{
private:
  int x;     //x座標
  int y;     //y座標
public:
  void setX(int a);  //X座標を設定(範囲外の値は0とする)
  void setY(int b);
  int getX(){return x;};
  int getY(){return y;};
};


//クラスメンバ関数の定義
void Point::setX(int a)
{
  if(a >= 0 && a <= 10){
    x = a;
  }
  else{
    cout << a << "は0-10の範囲外です。\n";
    cout << "0を代入します";
    x = 0;
  }
}
void Point::setY(int b)
{
  if(b >= 0 && b <= 10){
    y = b;
  }
  else{
    cout << b << "は0-10の範囲外です。\n";
    cout << "0を代入します";
    y = 0;
  }
}

int main()
{

  Point data1;

  int num1, num2;
  cout << "X座標を入力してください\n";
  cin >> num1;
  data1.setX(num1);

  cout << "Y座標を入力してください\n";
  cin >> num2;
  data1.setY(num2);

  cout << "座標は(" << data1.getX() << ',' << data1.getY() << ")です。\n";

  return 0;
}
