#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  map<string, int> name2salary;
  name2salary["John"] = 10000;
  name2salary["nick"] = 20000;
  name2salary["paul"] = 30000;
  cout << name2salary["nick"] << endl;
  if(name2salary.count("paul")) {
    cout << "paul is in the map" << endl;
  }
  for(map<string, int>::const_iterator it = name2salary.begin(); it != name2salary.end(); ++it) {
    cout << it->first << " : " << it->second << endl;
  }

  return 0;
}
