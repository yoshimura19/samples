#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  ifstream fin("test1.txt");   //ファイルをオープンする(ifstreamクラスのオブジェクトを作成)
  if(!fin){
    cout << "ファイルをオープン出来ませんでした。\n";
    return 1;
  }

  char str1[16];
  char str2[16];
  fin >> str1 >> str2;
  cout << "ファイルに書き込まれている2つの文字列は\n";
  cout << str1 << "です。\n";
  cout << str2 << "です。\n";

  fin.close();

  return 0;
}
