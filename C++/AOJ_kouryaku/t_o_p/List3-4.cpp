#include <iostream>
using namespace std;

// リストを使ってList 3-3 を書き直す(テキストCからC++)
struct ListNode{
  int data;
  ListNode *prev;
  ListNode *next;
};


int main()
{
  int buf;
  ListNode *firstnode, *lastnode, *newnode, *thisnode, *removenode;
  firstnode = lastnode = NULL;

  do {
    cout << "整数を入力してください(0を入力すると終了):";
    cin >> buf;      // scanf("%d", &buf);
    if(buf) {   // 新たな入力があったら、新しいノードを作成
      newnode = (ListNode* )malloc(sizeof(ListNode));
      newnode->data = buf;
      newnode->next = NULL;

      if(lastnode != NULL) {     // すでにあるリストの末尾に新しいノードをつなげる
        lastnode->next = newnode;
        newnode->prev = lastnode;
        lastnode = newnode;
      } else {
        firstnode = lastnode = newnode;    // これが最初の要素だった場合
        newnode->prev = NULL;
      }
    }
  } while(buf != 0);


  // 合計値を算出
  cout << "入力されたのは以下の数です\n";
  int sum = 0;
  for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next){
    cout << thisnode->data << " ";
    sum += thisnode->data;
  }
  cout << "合計値は" << sum << "です";

  // リストの全ノードを削除
  for(thisnode = firstnode; thisnode != NULL;){
    removenode = thisnode;
    thisnode = thisnode->next;
    free(removenode);
  }
  return EXIT_SUCCESS;
}

