#include <iostream>
using namespace std;

// Assignment 8a

const int N = 10;  // size_of_buffer

int my_strlen(char const * p);      // 自作strlen関数
void my_strcat(char * dest, int size_of_dest_buffer, char const * src);  // 自作strcat関数
int my_strncmp(char const * dest1, char const * dest2, int size); // 自作strncmp関数(文字列1,文字列2,比較文字数)

int main()
{
  char const * str = "hello, world";
  int const word_counts = my_strlen(str);
  cout << "自作strlen関数の出力:"<< word_counts << endl;


  char buffer[N];             // バッファサイズはグローバス変数で宣言
  strcpy(buffer, "1234567");  // ここでstrcpyはサイズ超えても書いてしまう(課題で要求されてないため今回は以下の関数中の処理で対応)
  my_strcat(buffer, sizeof(buffer), " 89123");
  cout << "自作strcat関数の出力:" << buffer << endl;


  char const * str2 = "ABC";
  cout << my_strncmp(str2, "ABD", 2) << endl;
  cout << my_strncmp(str2, "ABC", 2) << endl;
  cout << my_strncmp(str2, "AAA", 2) << endl;
  cout << my_strncmp(str2, "ABCD", 2) << endl;
  cout << my_strncmp(str2, "AB", 2) << endl;
  cout << my_strncmp(str2, "B", 2) << endl;
  cout << my_strncmp(str2, "A", 2) << endl;

  return 0;
}

int my_strncmp(char const * dest1, char const * dest2, int const size)
{
  for(int i = 0; i < size; i++) {
    if (dest1[i] > dest2[i]) {
      return 1;
      break;
    } else if (dest1[i] < dest2[i]) {
      return -1;
      break;
    }
  }
  return 0;   // sizeまで同じ文字列で大小関係がつかなかった場合
}
int my_strlen(char const * p)
{
  int i = 0;
  while(*p != '\0') {
    ++i;
    ++p;
  }
  return i;
}
void my_strcat(char * dest, int size_of_dest_buffer, char const * src)
{
  int position = 0;
  if (*src == '\0') return;  // an empty stringが渡された時用
  while(*dest != '\0') {
    ++dest;
    ++position;
  }
  do {
    if (position >= size_of_dest_buffer - 1) break; // 追加前にフルサイズ(strcpyが演算を通してしまうので以上にした)
    *dest = *src;
    ++dest;
    ++src;
    ++position;
    // cout << "追加中の位置: " << position << endl;
  } while (*src != '\0' || position == size_of_dest_buffer);
}
