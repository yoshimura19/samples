#include <iostream>
using namespace std;

// リストのなかのデータのサーチと削除
// リスト構成の詳細はList3-4.cpp参照

struct ListNode{
  int data;
  ListNode *prev;  // 前の要素へのポインタ
  ListNode *next;
};

int main()
{
  int buf;
  ListNode *firstnode, *lastnode, *newnode, *thisnode, *removenode;
  firstnode = lastnode = NULL;

  do {
    cout << "整数を入力してください(0を入力すると終了):";
    cin >> buf;    // scanf("%d", &buf);
    if(buf) {
      newnode = (ListNode* )malloc(sizeof(ListNode));
      newnode->data = buf;
      newnode->next = NULL;

      if(lastnode != NULL) {
        lastnode->next = newnode;
        newnode->prev = lastnode;
        lastnode = newnode;        // lastnodeの更新
      } else {
        firstnode = lastnode = newnode;   // これが最初の要素だった場合
        newnode->prev = NULL;
      }
    }
  } while(buf != 0);


  // 検索値を入力
  do {
    cout << "検索する値を入力してください:\n";
    cin >> buf;

    if(buf != 0){
      // 最初に入力した値のなかから検索し、見つかったら削除
      for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next){
        if(thisnode->data == buf){
          cout << "入力された値のなかに" << buf << "が見つかりました\n";
          cout << "ノードを削除します。\n";

          // ノードの削除
          if(thisnode->prev != NULL){
            thisnode->prev->next = thisnode->next;
          } else {
            firstnode = thisnode->next;
          }

          if(thisnode->next != NULL){
            thisnode->next->prev = thisnode->prev;
          }

          free(thisnode);
          break;
        }
      }
      if(thisnode == NULL) {
        cout << buf << "は入力されていないか、すでに削除されています。\n";
      }
    }
  } while(buf != 0);

  // 残ったノードをすべて削除
  for(thisnode = firstnode; thisnode != NULL;) {
    removenode = thisnode;
    thisnode = thisnode->next;
    free(removenode);
  }

  return EXIT_SUCCESS;
}
