#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int const M = 1046527;
int const NIL = -1;
int const L = 14;
char H[M][L];

int getString(char ch);  // 文字列から数値に
long long getKey(char str[]);  // 文字列から数値へ変換しkeyを生成
int h1(int key){ return key % M; }
int h2(int key){ return 1 + (key % (M - 1)); }

int find(char str[]);  // 辞書にあるか調べる
int insert(char str[]); // 辞書に追加

int main()
{
  int h;
  char str[L];    // strは与えられる文字列(長さ<=12)
  char com[9];    // comは命令insertかfind
  for(int i = 0; i < M; i++) H[i][0] = '\0';

  int n;          // 命令の数
  scanf("%d", &n);
  //printf("%d",n);
  for(int i = 0; i < n; i++) {
    scanf("%s %s", com, str);

    if(com[0] == 'i') {
      insert(str);
    } else {
      if ( find(str) ){
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }
  return 0;
}

int getString(char ch) {  // 文字列から数値に
  if( ch == 'A') return 1;
  else if( ch == 'C') return 2;
  else if( ch == 'G') return 3;
  else if( ch == 'T') return 4;
  else return 0;
}
long long getKey(char str[]){  // 文字列から数値へ変換しkeyを生成
  long long sum = 0, p = 1;
  for(int i = 0; i < strlen(str); i++) {
    sum += p * (getString(str[i]));
  }
  return sum;
}
int find(char str[]){  // 辞書にあるか調べる
  long long key, h;
  key = getKey(str);
  for(int i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h],str) == 0) return 1;
    else if ( strlen(H[h]) == 0 ) return 0;
  }
  return 0;
}
int insert(char str[]){; // 辞書に追加
  long long key, h;
  key = getKey(str);  // 文字列を数値に変換
  for (int i = 0 ;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if(strcmp(H[h],str) == 0) return 1;  // 辞書登録済み
    else if ( strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return 0;
    }
  }
  return 0;
}
