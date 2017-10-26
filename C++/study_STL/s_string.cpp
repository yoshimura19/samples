#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(const string &str, char sep);  // split関数

/* ***
std::string は std::vector とよく似ている。size(), push_back() など、用意されているメンバ関数もほぼ同じで、 文字列特有のメンバ関数がいくつか用意されている。
vector との大きな違いは、文字列の最後にヌル文字（'\0'）が格納されている点だ。
*** */

int main()
{
  string str(10, 'a');
  // char *data = "hoge";  // ポインタ利用
  // warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
  // string str0(data);

  string str1("12"); string str2("xyz");
  string str3 = str1 + str2;   // operator+())

  cout << str3 << endl;
  cout << str2 + str1 << endl;

  /* *** 文字文字列の追加 *** */
  string str4;
  str.push_back('Z');   // 末尾に'Z'を追加
  str += '0';       // push_backまたは+=
  // remark +=は文字列も追加できるので通常は+=が通常使用される
  cout << str << endl;
  cout << "1234" + str << endl;   // 先頭に文字列を追加したいとき
  // push_back(), +=演算子ともに処理時間はO(1)
  str.insert(str.begin() + 2, '-');   // insert(イテレータ,文字):イテレータ
  // insert()の処理時間はO(N) (配列で文字列をずらす処理をしている)


  /* *** 文字列の削除 *** */
  str.pop_back();  // 末尾削除
  // pop_back()はvoid型なので、最後の文字を取り出す場合はback()を使用
  // 任意の位置を削除するときはerase(iterator)
  str.erase(str.begin() + 2);
  str.erase(str.begin() + 2, str.begin() + 4);  // [first, last)の文字を一度に削除)


  /* *** その他のメンバ関数 *** */
  // .size() .length() どちらも文字数を返す(vectorに対応させて.size())

  /* *** 文字列の一部を取得 *** */
  string str5 = "abcxyz";
  string sub = str.substr(2, 3);  // [2]の位置から3文字
  cout << sub << endl;

  // stringは通常文字列と同じようにデータ領域が連続したアドレスなので、文字列アドレスを他の関数に渡して処理する事も可能
  //  cout << strlen(str.c_str()) << "\n";  // error


  /* *** 文字列検索・置換 *** */
  // find(検索文字列, 開始位置=0)末尾に向って検索
  cout << (int)str.find("b") << "\n";  // マッチする場合
  cout << (int)str.find("b", 3) << "\n";  // 3文字目から末尾に向って検索
  cout << (int)str.find("x") << "\n";  // マッチしない場合
  // rfind(検索文字列、検索開始位置)指定位置から先頭に向って検索

  str.replace(1, 2, "xyz");  // replace(位置、置換文字数、置換文字列
  cout << str << endl;


  /* *** 数値をstring文字列に変換 *** */
  //string s = tostr(123);  // 整数を文字列に変換

  string s = to_string(123);   // C++11から
  cout << s << endl;

  /* *** 文字列の配列 *** */
  vector<string> strvect = {    // 文字列配列
    "abc", "123", "xyzz"
  };
  // 途中の操縦削除が頻繁な場合は list<string> strlistを利用する


  /* *** 文字列比較 *** */
  // == != < <= > >=が定義されている

  /* *** 文字列分割 *** */
  // stringにはsplitメソッドがないので自分で定義しなくてはいけない
  // boostのアルゴリズムライブラリにある()

  // getline()を使ってsplit関数を定義する
  string longs = "asdf, asdfnet., naietaksjrena, aniwerh, jiaosdnf";
  vector<string> result = split(longs, ',');
  for (auto x : result) {
    cout << x << endl;
  }

  return 0;
}

vector<string> split(const string &str, char sep)
{
  vector<string> v;
  stringstream ss(str);
  string buffer;
  while (getline(ss, buffer, sep)) {  /// getline()は通常改行でテキストを分割するが第三引数で分割文字を指定可
    v.push_back(buffer);
  }
  return v;
}
