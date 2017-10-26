#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

// stackは後入れ先だし(LIFO)でのデータ管理 

int main(){
  // 標準ライブラリからstackを使用
  stack<int> S;   // int型の要素を管理するスタックを生成(オブジェクト)
  int a, b;
  string s;

  cout << "EOFかバックスラッシュ\\で終了\n";
  while (cin >> s){
    if (s[0] == '\\') break;
    if (s[0] == '+') {
      a = S.top(); S.pop(); // top(): スタックの頂点の要素を返す
      b = S.top(); S.pop(); // pop(): スタックから要素を取り出し削除
      S.push(a+b);   // push(x): スタックに要素xを追加
    }
    else if (s[0] == '-') {
      b = S.top(); S.pop();
      a = S.top(); S.pop();
      S.push(a-b);
    }
    else if (s[0] == '*') {
      a = S.top(); S.pop();
      b = S.top(); S.pop();
      S.push(a * b);
    }
    else {
      S.push(atoi(s.c_str()));  // atoiは文字列から数値(cstdlib)
    }
  }

  int x = S.top();
  cout << x << endl;

  return 0;
}
