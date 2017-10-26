#include <iostream>
using namespace std;

//クラスの宣言
class Car{

private:
  int num;
  double gas;
public:
  int getNum(){return num;};
  double getGas(){return gas;};
  void show();
  void setNumGas(int n, double g);
};

//Carクラスメンバの定義
void Car::show()
{
  cout << "車のナンバは" << num << "です。\n";
  cout << "ガソリン量は" << gas << "です。\n";
}

void Car::setNumGas(int n, double g)
{
  if(g > 0 && g < 1000){
    num = n;
    gas = g;
    cout << "ナンバを" << num << "にガソリン量を" << gas << "にしました\n";
  }
  else{
    cout << g << "は正しいガソリン量ではありません。\n";
    cout << "ガソリン量を変更出来ませんでした。\n";
  }
}

int main()
{
  Car car1;

  //このようなアクセスは出来なくなります。
  //car1.num = 1234;
  //car2.gas = 20.5;

  car1.setNumGas(1234, 20.5);
  car1.show();

  cout << "正しくないガソリン量を(-10.0)を指定してみます。...\n";
  car1.setNumGas(1234, -10.0);

  cout << "インライン関数での出力" << car1.getNum() << "と" << car1.getGas() << "\n";

  return 0;
}
