#include <iostream>
using namespace std;

int my_strlen(char const *p);

int main(int argc, char** argv)
{
  char const * t = "hello";
  cout << my_strlen(t) << endl;

  return 0;
}

int my_strlen(char const * p)
{
  int i = 0;
  while(*p != '\0') {
    ++i;
    ++p;
  }
  return i;
}
