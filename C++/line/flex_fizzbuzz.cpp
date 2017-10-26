#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(const string &str, char sep);

int main(int argc, char *argv[])  // 最後は自然数の引数
{
  for (int i = 1; i < argc; i++) {
    printf ("argv[%i]: %s\n", i, argv[i]);
  }

  vector<string> temp;
  map<int, string> fb;
  for (int i = 1; i < argc - 1; i++) {
    string s = argv[i];
    temp = split(s, ':');
    fb[stoi(temp[0])] = temp[1];
  }
  string n0 = argv[argc];
  int n = stoi(n0);

  for (auto itr = fb.begin(); itr != fb.end(); ++itr) {
    cout << "key = " << itr->first                // キーを表示
         << ", val = " << itr->second << "\n";    // 値を表示
  }

  //for ()

  return 0;
}


vector<string> split(const string &str, char sep)
{
  vector<std::string> v;
  stringstream ss(str);
  string buffer;
  while( getline(ss, buffer, sep) ) {
    v.push_back(buffer);
  }
  return v;
}
