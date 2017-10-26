#include <iostream>
using namespace std;

int main()
{
  int num;
  cout << "1~9までの数を入力してください";
  cin >> num;

  try{
    if(num <= 0)
      throw "0以下を入力しました";
    if(num >= 10)
      throw "10以上を入力しました";

    cout << num << "です。\n";
  }

  catch(char* err){
    cout << "エラー:" << err << '\n';
    return 1;
  }
  return 0;
}
