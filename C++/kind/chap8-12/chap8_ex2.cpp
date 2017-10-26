#include <iostream>
using namespace std;

void add(int* x1, int* x2, int add_point);

int main()
{
  int x1, x2, add_point;
  cout << "Input two test scores:\n";
  cin >> x1 >> x2;

  cout << "Input the points which wants to add:\n";
  cin >> add_point;

  add(&x1, &x2, add_point);

  cout << "Score1 is " << x1 << ".\n";
  cout << "Score2 is " << x2 << ".\n";

  return 0;
}

void add(int* x1, int* x2, int add_point)
{
  *x1 += add_point;
  *x2 += add_point;
}
