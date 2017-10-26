#include <iostream>
using namespace std;

int count(char str[], char ch);

int main()
{
  char str[100];
  char ch;

  cout << "Input a string of characters\n";
  cin >> str;
  cout << "Input a character which you want to search.\n";
  cin >> ch;

  cout << "In \"" << str << "\"," << " there is(are) " << count(str, ch) << ' ' << ch <<".\n";

  return 0;
}

int count(char str[], char ch)
{
  int j = 0;
  for(int i=0; str[i] != '\0'; i++){
    if(str[i] == ch){
      j++;
    }
  }
  return j;
}
