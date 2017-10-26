#include <iostream>
using namespace std;

int main()
{

  /* exercise 1 */
  cout << "0-4= " << 0-4 << '\n';
  cout << "3.14*2= " << 3.14*2 << '\n';
  cout << "5 / 3 = " << (double)(5) / 3 << '\n';
  cout << "mod(30 / 7) = " << 30 % 7 << '\n';
  cout << "(7 + 32) / 5 = " << (double)(7 + 32) / 5 << '\n';

  /* exercise 2 */
  int height, base;
  cout << "Input height:\n";
  cin >> height;
  cout << "Input base:\n";
  cin >> base;
  cout << "The area of a triange is " << double(height * base) / 2 << '\n';

  /* exercise 3 */
  int sum=0, num=0;
  double average;

  cout << "Input a score of subject 1:\n";
  cin >> num;
  sum += num;
  cout << "Input a score of subject 2:\n";
  cin >> num;
  sum += num;
  cout << "Input a score of subject 3:\n";
  cin >> num;
  sum += num;
  cout << "Input a score of subject 4:\n";
  cin >> num;
  sum += num;
  cout << "Input a score of subject 5:\n";
  cin >> num;
  sum += num;

  cout << "The sum of scores is " << sum << '\n';
  average = (double)sum / 5;
  cout << "The average of scores is " << average << '\n';

  return 0;
}
