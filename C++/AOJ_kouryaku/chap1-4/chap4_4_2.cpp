#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
  int key;
  Node *next, *prev;
};

Node *nil;

Node* listSearch(int key) {
  Node *cur = nil-> next;  // 番兵の次の要素から辿る
  while ( cur != nil && cur->key != key ) {
    cur = cur->next;
  }
  return cur;
}

void init() {    // （先頭を指す特別なノード）番兵を示すNILのノード
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void printList() {
  Node *cur = nil->next;
  int isf = 0;
  while ( 1 ) {
    if (cur == nil) break;
    if (isf++ > 0) printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
  }
  printf("\n");
}

void deleteNode(Node *t) {
  if (t == nil) return;  // tが番兵の場合は処理しない
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() {
  deleteNode(nil->next);
}

void deleteLast() {
  deleteNode(nil->prev);
}

void deleteKey(int key) {
  deleteNode(listSearch(key));
}

void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;   // 番兵の直後に要素を追加(図4.10参照)
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

int main() {
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;

  // 命令数の入力
  scanf("%d", &n);
  init();            // 番兵の設置
  /* 入力の形式
     insert x: 連結リストの先頭にキーxを持つ要素を継ぎ足す
     delete x: キーxを持つ最初の要素を削除する
     deleteFirst: 連結リストの先頭の要素を削除する
     deleteLast: 連結リストの末尾の要素を削除する
  */

  for ( i = 0; i < n; i++){
    scanf("%s%d", com, &key);  // より高速な入力関数を使用
    if ( com[0] == 'i' ){ insert(key); np++; size++; }
    else if ( com[0] == 'd' ){
      if ( strlen(com) > 6) {
        if( com[6] == 'F') deleteFirst();
        else if( com[6] == 'L') deleteLast();
      } else {
        deleteKey(key); nd++;
      }
      size--;
    }
  }

  printList();

  return 0;
}
