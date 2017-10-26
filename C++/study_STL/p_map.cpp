#include <iostream>
#include <map>
using namespace std;

int main()
{
  map<int, int> mp3;
  const int N = 100;
  for (int i = 0; i < N; i++) {
    mp3[rand()] = rand();
  }
  for (auto itr = mp3.begin(); itr != mp3.end(); ++itr) {
    cout << itr->first << ": " << itr->second << '\n';
  }
  // キーは昇順に並ぶ

  map<string, int> mp2;
  mp2["def"] = 1; mp2["abc"] = 1; mp2["cde"] = 4; mp2["bcd"] = 3;
  for (auto itr = mp2.begin(); itr != mp2.end(); ++itr) {
    cout << itr->first << ": " << itr->second << '\n';
  }

  multimap<string, int> mp;
  mp.insert(make_pair("abc", 777));
  mp.insert(make_pair("abc", 1));
  mp.insert(make_pair("xyz", 123));
  mp.insert(make_pair("abc", 999));
  auto ptr = mp.lower_bound("abc");
  auto last = mp.upper_bound("abc");
  while (ptr != last) {
    if (ptr->second == 999)
      ptr = mp.erase(ptr);   // 消してitr進める
    else
      ++ptr;
  }

  cout << "全部表示" << endl;
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    cout << it->first << ':' << it->second << endl;
  }
  cout << "abcだけ表示" << endl;
  //pair<string, int> range = mp.equal_range("abc");

  // for (auto x : mp["abc"]) {
  //   cout << x->first << ':' << x->second << endl;
  // }

  return 0;
}
