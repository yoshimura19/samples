#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main()
{
  int n;
  char str[10], com[13];
  map<string, bool> T;

  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%s%s", com, str);
    if (com[0] == 'i' ) T[string(str)] = true;
    else {
      if ( T[string(str)] ) printf("yes\n");
      else printf("no\n");
    }
  }

  // printf("\n");
  // char test[] = "trying";
  // //test1 = string(test);
  // cout << string(test) << endl;

  return 0;
}
