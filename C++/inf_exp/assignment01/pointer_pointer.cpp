#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  char str[] = "kitty on your lap";
  char *str_p;
  char **str_pp;

  str_p = str;
  str_pp = &str_p;

  cout << "\n文字型配列変数" << '\n';
  cout << "配列先頭アドレス = " << &str << '\n';
  cout << "保持する文字列 = " << str << "\n\n";

  cout << "ポインタの示す値" << '\n';
  cout << "ポインタアドレス" << &str_p << endl;
  cout << "保持する値 = " << *str_p << endl;
  cout << "保持するアドレスが持つ内容" << str_p << "\n\n";

  cout << "ポインタのポインタが示す値" << endl;
  cout << "保持する値" << str_pp << endl;
  cout << "保持する値が持つ値" << **str_pp << endl;
  cout << "保持する値が持つ値の内容" << *str_pp << "\n\n";


  return 0;
}

