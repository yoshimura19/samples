#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int main()
{
  char com[20];
  priority_queue<int> PQ;    // STLのqueue

  while (1) {
    scanf("%s", com);
    if (com[0] == 'i') {
      int key ; scanf("%d", &key);
      PQ.push(key);
    } else if (com[1] == 'x') {    // e'x'tract
      printf("%d\n", PQ.top());
      PQ.pop();  // 先頭要素削除
    } else if (com[0] == 'e') {   // 'e'nd
      break;
    }
  }

  return 0;
}
