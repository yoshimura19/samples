#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
  double real;
  double imag;
public:
  Complex() { double real = 0; double imag = 0;}
  void set(double real_value, double imag_value) {real = real_value; imag = imag_value;};
  void show() {cout << "real_value:" << real << " imag_value:" << imag << '\n';};
  // void plus(Complex& b) { real = real + b.real; imag = imag + b.imag;};
  Complex plus(Complex & b);   // 複素数の加減乗除と絶対値
  Complex minus(Complex& b);
  double abs() {return sqrt(real * real + imag * imag);};
  Complex mul(Complex& b);
  Complex div(Complex& b);

  // C''とD''を結ぶ直線と実軸の交点を求める
  Complex find_intersection_point(Complex& d);
  int check_exist_intersection();  // 交点存在のcheck(1:交点あり,0:なし)
};

Complex Complex::plus(Complex &b)
{
  Complex r;
  r.real = real + b.real;
  r.imag = imag + b.imag;
  return r;
}
Complex Complex::minus(Complex &b)
{
  Complex r;
  r.real = real - b.real;
  r.imag = imag - b.imag;
  return r;
}
Complex Complex::mul(Complex &b)
{
  Complex r;
  r.real = real * b.real - imag * b.imag;
  r.imag = imag * b.real + real * b.imag;
  return r;
}
Complex Complex::div(Complex &b)
{
  Complex r;
  double const abs_val = b.abs();
  double const numerator = b.abs() * b.abs();
  r.real = (real * b.real + imag * b.imag) / numerator;
  r.imag = (imag * b.real - real * b.imag) / numerator;
  return r;
}
Complex Complex::find_intersection_point(Complex& d)
{
  Complex P_double_prime;
  P_double_prime.imag = 0;  // 座標変換後なので
  // ここは1次方程式を紙の上で計算した結果
  P_double_prime.real = d.real - d.imag * ((real - d.real) / (imag - d.imag));
  return P_double_prime;
}
int Complex::check_exist_intersection()
{
  if (0 <= real && real <= 1) {
    cout << "交点あり\n";
    return 1;
  } else {
    cout << "交点なし\n";
    return 0;
  }
}


int main()
{
  // Complexクラスの演算は元の変数を書き換えず新しい変数を用意する
  Complex A, B, C, D;
  A.set(1,1); B.set(5,3); C.set(2,3); D.set(5,0);  // 手計算済み座標例


  // 複素平面上の直線ABとCDの交点Pの座標を求めるプログラム

  // Step1 Aの座標をそれぞれの座標から引く(平行移動)
  // A'が原点になる
  Complex A_prime = A.minus(A);
  Complex B_prime = B.minus(A);
  Complex C_prime = C.minus(A);
  Complex D_prime = D.minus(A);

  // Step2 B'でそれぞれのプライムにした座標を割る(回転+拡大縮小)
  // 変換後のA'' B''は実軸上の座標になる
  Complex A_double_prime = A_prime.div(B_prime);
  Complex B_double_prime = B_prime.div(B_prime);
  Complex C_double_prime = C_prime.div(B_prime);
  Complex D_double_prime = D_prime.div(B_prime);

  // Step3 C''とD''を結ぶ直線と実軸の交点を求める(交点の有無の判定をする)
  Complex P_double_prime = C_double_prime.find_intersection_point(D_double_prime);
  int flag = P_double_prime.check_exist_intersection();

  // Step4 P''にStep2と1の逆演算を施して座標Pを求める
  Complex P_prime;
  Complex P;
  if(flag == 1){
    P_prime = P_double_prime.mul(B_prime);
    P = P_prime.plus(A);
  }


  // 入力値の確認
  A.show();
  B.show();
  C.show();
  D.show();
  cout << '\n';

  // Step1後
  A_prime.show();
  B_prime.show();
  C_prime.show();
  D_prime.show();
  cout << '\n';

  // Step2後
  A_double_prime.show();
  B_double_prime.show();
  C_double_prime.show();
  D_double_prime.show();
  cout << '\n';

  // Step3後
  P_double_prime.show();
  cout << '\n';

  // Step4後
  if(flag == 1){
    P_prime.show();
    cout << "交点Pの座標:\n";
    P.show();
  } else { // flag == 0;
    cout << "交点Pは存在しないABCDの座標の組です\n";
  }


  // 自作複素数クラス動作確認
  // Complex a, b;

  // a.set(9, 11);
  // a.show();
  // b.set(4, -9);
  // b.show();

  // Complex a_plus_b = a.plus(b);
  // Complex a_minus_b = a.minus(b);
  // Complex a_mul_b = a.mul(b);
  // Complex a_div_b = a.div(b);

  // cout << "plus:"; a_plus_b.show();
  // cout << "minus:"; a_minus_b.show();
  // cout << "multiply:"; a_mul_b.show();
  // cout << "div:"; a_div_b.show();

  // double z = a.abs(); cout << z << endl;

  return 0;
}
