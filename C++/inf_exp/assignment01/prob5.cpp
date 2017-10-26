#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
  // とりあえずキーボードn組入力にしとく
  int n = 7;
  // cin >> n;

  map<string, int> friends_dict;   // 友だちの数リストを作る

  for(int i = 0; i < n; i++){
    char person1[100];
    char person2[100];
    cin >> person1 >> person2;
    if(friends_dict.count(person1) == 0) {
      // cout << "新しい友だちの組です\n";
      friends_dict[person1] = 1;
    } else {
      // cout << "友だちが多いフレンズなんだね！\n";
      friends_dict[person1] += 1;
    }
    if(friends_dict.count(person2) == 0) {
      // cout << "新しい友だちの組です\n";
      friends_dict[person2] = 1;
    } else {
      // cout << "友だちが多いフレンズなんだね！\n";
      friends_dict[person2] += 1;
    }
  }

  //char max_person[100];   // このやり方不可だった
  int max_friends = 0;
  for( map<string, int>::const_iterator it = friends_dict.begin(); it != friends_dict.end(); ++it) {
    // cout << it->first << " : " << it->second << endl; // 友だちの数出力
    if(max_friends <= it->second) {
      max_friends = it->second;
      // max_person = it->first;
    }
  }
  // cout << max_person << " : " << max_friends << endl;

  // max_person使えないので(時間の制約上)下の方法を採用
  for( map<string, int>::const_iterator it = friends_dict.begin(); it != friends_dict.end(); ++it) {
    if(max_friends == it->second) {
      cout << "一番友だちが多い人はこの人です。\n";
      cout << it->first << " : " << it->second << endl;
      break;
    }
  }

  return 0;
}
