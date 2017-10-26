#include <iostream>
using namespace std;

//Arrayクラステンプレート
template <class T>
class Array{
private:
  T data[5];
public:
  void setData(int num, T d);
  T getData(int num);
};

template <class T>          //クラステンプレートのメンバ関数の定義
void Array<T>::setData(int num, T d)
{
  if(num < 0 || num > 4)
    cout << "配列の範囲を超えています。\n";
  else
    data[num] = d;
}
template <class T>
T Array<T>::getData(int num)
{
  if(num < 0 || num > 4){
    cout << "配列の範囲を超えています。\n";
    return data[0];
  }
  else
    return data[num];
}

int main()
{
  cout << "int型の配列を作成します。\n";
  Array<int> i_array;           //int型を扱うクラス・オブジェクトを作成する。
  i_array.setData(0, 80);
  i_array.setData(1, 60);
  i_array.setData(2, 58);
  i_array.setData(3, 77);
  i_array.setData(4, 57);

  for(int i=0; i<5; i++)
    cout << i_array.getData(i) << '\n';


  cout << "double型の配列を作成します。\n";
  Array<double> d_array;           //double型を扱うクラス・オブジェクトを作成する。
  d_array.setData(0, 35.5);
  d_array.setData(1, 45.6);
  d_array.setData(2, 26.8);
  d_array.setData(3, 76.2);
  d_array.setData(4, 85.5);

  for(int j=0; j<5; j++)
    cout << d_array.getData(j) << '\n';

  return 0;
}
