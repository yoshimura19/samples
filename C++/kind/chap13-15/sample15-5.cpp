#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int num;
  vector<int> vt;

  cout << "いくつ整数データを入力しますか？\n";
  cin >> num;

  for(int i=0; i< num; i++){
    int data;
    cout << "整数を入力してください。\n";
    cin >> data;
    vt.push_back(data);
  }

  cout << "表示します。\n";
  vector<int>::iterator it = vt.begin();  //先頭のデータを知る事ができる
  while(it != vt.end()){      //vt.end() 末尾のデータを知る事ができる
    cout << *it;
    cout << "-";
    it++;
  }
  cout << "\n";
}
