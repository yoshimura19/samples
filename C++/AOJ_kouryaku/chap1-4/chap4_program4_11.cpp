#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

// ALDS1_3_C 連結リストp95の問題のライブラリ使用版


int main() {
  int q, x;    // qはquery(問い合わせ)数
  char com[20];

  list<int> v;   // 標準ライブラリよりlistを使用
  scanf("%d", &q);
  for (int i = 0; i < q; i++){
    scanf("%s", com);
    if ( com[0] == 'i' ){ // insert
      scanf("%d", &x);
      v.push_front(x);
    } else if ( com[6] == 'L' ){ // deleteList
      v.pop_back();
    } else if ( com[6] == 'F' ){ // deleteFirst
      v.pop_front();
    } else if ( com[0] == 'd' ){ // delete
      scanf("%d", &x);
      for ( list<int>::iterator it = v.begin(); it != v.end(); it++) {
        if ( *it == x ){   // begin(): リストの先頭を指すイテレータを返す。
          v.erase(it);
          break;
        }
      }
    }
  }
  int i = 0;
  for (list<int>::iterator it = v.begin(); it != v.end(); it++ ){
    if (i++) printf(" ");
    printf("%d", *it);
  }
  printf("\n");

  return 0;
}
