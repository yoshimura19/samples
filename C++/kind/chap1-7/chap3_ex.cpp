#include <iostream>
using namespace std;

int main()
{
  double pi;
  char alphabet;
  int height, weight;

  cout << "What is the value of pi:";
  cin >> pi;
  cout << "The value of pi is " << pi << '\n';

  cout << "What is the first alphabet in English:\n";
  cin >> alphabet;
  cout <<  "The fisrt alphabet in English is " << alphabet << '\n';

  cout << "Input your height and weight:";
  cin >> height >> weight;
  cout << "Your height is " << height << '\n';
  cout << "Your weight is " << weight << '\n';

  return 0;
}
