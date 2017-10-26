#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  /* sample 9-11 */
  char str[100];

  cout << "Input characters of string.\n";
  cin >> str;

  cout << "The length of characters of string is " << strlen(str) << ".\n";


  /* sample 9-12 */
  char str0[20];
  char str1[10];
  char str2[10];

  strcpy(str1, "Hello");
  strcpy(str2, "Goodbye");
  strcpy(str0, str1);
  strcat(str0, str2);

  cout << "Array str1 is " << str1 << ".\n";
  cout << "Array str2 is " << str2 << ".\n";
  cout << "The result of concat is " << str0 << ".\n";

  return 0;
}
