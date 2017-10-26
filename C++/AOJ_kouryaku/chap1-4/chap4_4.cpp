#include <iostream>
using namespace std;

// 連結リスト
// t_o_pフォルダのリストも参照

struct Node {
  int key;
  Node *prev, *next;  // 前後要素へのポインタ
};

Node *nil;

// 番兵と呼ばれる、リストの先頭を指す特別なノードの設置(番兵を表すNILノード)
void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void insert(int key) {   // 双方向リストへの要素の挿入（先頭に）
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

Node* listSearch(int key) {
  Node *cur = nil->next;  // 番兵の次の要素から辿る
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void deleteNode(Node *t) {
  if (t == nil) return;  // tが番兵の場合は処理しない
  t->prev->next = t->next;   // 図4.11参照
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
  // 検索したノードを削除
  deleteNode(listSearch(key));
}

int main()
{
  return 0;
}
