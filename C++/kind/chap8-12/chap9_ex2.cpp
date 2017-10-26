#include <iostream>
using namespace std;

int length(char* str);

int main()
{
  char* str0;

  cout << "Input a string of characters\n";
  cin >> str0;

  cout << "The length of a string of characters is " << length(str0) << ".\n";

  return 0;
}

int length(char* str)
{
  int i = 0;
  for(i=0; str[i] != '\0'; i++);
  return i;
}
