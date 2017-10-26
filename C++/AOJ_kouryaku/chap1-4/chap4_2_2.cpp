#include <iostream>
using namespace std;

static const int LEN = 10005;   // リングバッファ形式なので、LENは最大格納数

// プロセス構造体  キュー（プロセス数と処理時間を与える）
struct Process {     // クオンタム(最大qms)だけ処理を行う
  char name[100];
  int t;
};

// グローバル変数
Process Q[LEN];
int head, tail;

// キューに出し入れ関数の宣言
void enqueue(Process x);
Process dequeue();
int min(int a, int b) {return a < b ? a : b;}

int main()
{
  int n, q;    // プロセス数, クオンタム
  cin >> n >> q;

  for(int i = 1; i <= n; i++){
    cin >> Q[i].name >> Q[i].t;
  }
  head = 1, tail = n + 1;

  // シュミレーション
  int elaps = 0;    // 終了時刻の出力用
  int c;            // 未完了プロセス格納
  while (head != tail){
    Process u;
    u = dequeue();
    c = min(q, u.t);  // クオンタムまたは必要な時間数だけ処理
    u.t -= c;
    elaps += c;   // 経過時間を加算
    if (u.t > 0) enqueue(u); // 処理が終了していなければ追加
    else cout <<  u.name << ' ' << elaps << endl;
  }

  return 0;
}

void enqueue(Process x){
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}
Process dequeue(){
  Process x = Q[head];
  head = (head + 1) % LEN;
  return x;
}
