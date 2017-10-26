#include <iostream>
using namespace std;

//Pointクラスの宣言
class Point{
private:
  int x;
  int y;
public:
  Point(int a=0, int b=0){x=a; y=b;}
  void show(){cout << "x :" << x << " y :" << y << '\n';}
  void setX(int a){x = a;}
  void setY(int b){y = b;}
  Point operator+(Point p);   //演算子のオーバーロード
};

//Pointクラスメンバ関数の定義
//Pointクラス型の引数を1つとり、Pointクラス型の値を戻すoperator+()という名の演算子関数
Point Point::operator+(Point p)
{
  Point tmp;
  tmp.x = x + p.x;
  tmp.y = y + p.y;
  return tmp;
}

//Pointクラスの利用
int main()
{
  Point p1(1, 3);
  Point p2(5, 2);

  p1.show();
  p2.show();

  p1 = p1 + p2;  // +演算子が使えるようになっている
  p1.show();

  return 0;
}
