#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

// Program 9.2:二分探索木の探索

struct Node {
  int key;
  Node *right, *left, *parent;
};

Node *root, *NIL;     // NILを表す適当なアドレス (rootは最初のkeyの時初期化)

Node * find(Node *u, int k) {  // find( rootのオブジェクト, key)
  while ( u != NIL && k != u->key ) {
    if (k < u->key) u = u->left;
    else u = u->right;
  }
  return u;    // NILが帰ったらkeyなし
}

void insert(int k) {   // 節点のキー
  Node *y = NIL;      // 親用
  Node *x = root;     // rootを起点に下のwhile文で探す(挿入位置探索用)
  Node *z;            // 自分

  z = (Node *)malloc(sizeof(Node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if ( z->key < x->key ) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;      // 探索完了なので親を登録
  if( y == NIL) {
    root = z;
  } else {               // 親のオブジェクトにどちらの子であるか登録
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node *u) {
  if (u == NIL) return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}
void preorder(Node *u) {
  if (u == NIL) return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}


int main() {
  int n, x;
  string com;

  scanf("%d", &n);     // 命令数

  for (int i = 0; i < n; i++) {
    cin >> com;
    if ( com[0] == 'f') {
      scanf("%d", &x);
      Node *t = find(root, x);
      if (t != NIL) printf("yes\n");
      else printf("not\n");
    } else if (com == "insert") {
      scanf("%d", &x);
      insert(x);
    } else if ( com == "print") {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
  }

  return 0;
}
