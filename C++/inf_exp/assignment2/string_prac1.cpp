#include <iostream>
using namespace std;

// void my_strcat(char const * s, char* t);
 void my_strcat2(char * s, char const * t);

int main(int argc, char* argv[])
{
  char buffer[256];
  strcpy(buffer, "Hello");
  my_strcat2(buffer, ", world!");
  cout << buffer << endl;

  return 0;
}

void my_strcat2(char * s, char const * t)
{
  while(*s != '\0') {
    ++s;
  }
  do {
    *s = *t;
    ++s;
    ++t;
  } while (*t != '\0');
  *s = *t;
}


// 慣れてる人版
// void my_strcat(char const * s, char* t)
// {
//   while (*s != '\n') ++s;
//   while ((*s++ = *t++) != '\0');
// }
