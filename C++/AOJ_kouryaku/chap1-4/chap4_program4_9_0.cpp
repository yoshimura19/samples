#include <iostream>
#include <queue>
#include <string>
using namespace std;

// キューは先入先出し(FIFO)のデータ管理

int main() {
  queue<string> Q;    // string型の要素を管理するキュー(オブジェクト)

  Q.push("red");
  Q.push("yellow");
  Q.push("yellow");
  Q.push("blue");

  cout << Q.front() << " ";
  Q.pop();

  cout << Q.front() << " ";
  Q.pop();

  cout << Q.front() << " ";
  Q.pop();

  Q.push("green");

  cout << Q.front() << " ";
  Q.pop();

  cout << Q.front() << endl;

  return 0;
}
