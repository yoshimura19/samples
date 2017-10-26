#include <iostream>
#include <cmath>
using namespace std;

struct Complex {
  double real;
  double imag;
  Complex() {}
};

void set_to_complex(Complex *p, double real_value, double imag_value)
{
  p->real = real_value;
  p->imag = imag_value;
}

Complex calc_comp_plus_comp(Complex *a, Complex *b)
{
  Complex r;
  r.real = a->real + b->real;
  r.imag = a->imag + b->imag;
  return r;
}

Complex calc_comp_minus_comp(Complex *a, Complex *b)
{
  Complex r;
  r.real = a->real - b->real;
  r.imag = a->imag - b->imag;
  return r;
}

Complex calc_comp_mul_comp(Complex *a, Complex *b)
{
  Complex r;
  r.real = a->real * b->real - a->imag * b->imag;
  r.imag = a->imag * b->real + a->real * b->imag;
  return r;
}

double calc_abs_of_complex(Complex *p)
{
  return sqrt(p->real * p->real + p->imag * p->imag);
}

Complex calc_comp_div_by_comp(Complex *a, Complex *b)
{
  Complex r;
  const double abs_val = calc_abs_of_complex(b);
  const double r_numerator = abs_val * abs_val;
  r.real = (a->real * b->real + a->imag * b->imag) / r_numerator;
  r.imag = (a->imag * b->real - a->real * b->imag) / r_numerator;
  return r;
}

int main()
{
  Complex a, b, c;
  set_to_complex(&a, 9, 11);
  set_to_complex(&b, 4, -9);

  cout << "The value inputed" << " a = " << a.real << " + " << a.imag << "i" << endl;
  cout << "The value inputed" << " b = " << b.real << " + " << b.imag << "i" << endl;

  Complex a_plus_b = calc_comp_plus_comp(&a, &b);
  cout << "a + b = " << a_plus_b.real << " + " << a_plus_b.imag << "i" << endl;

  Complex a_minus_b = calc_comp_minus_comp(&a, &b);
  cout << "a - b = " << a_minus_b.real << " + " << a_minus_b.imag << "i" << endl;

  Complex a_cul_b = calc_comp_mul_comp(&a, &b);
  cout << "a * b = " << a_cul_b.real << " + " << a_cul_b.imag << "i" << endl;

  double z = calc_abs_of_complex(&a);
  cout << "absolute value of a ";
  cout << z << endl;


  Complex a_b = calc_comp_div_by_comp(&a, &b);
  cout << "a / b = " << a_b.real << " + " << a_b.imag << "i" << endl;

  return 0;
}
