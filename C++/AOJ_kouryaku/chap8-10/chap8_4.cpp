#include <cstdio>
using namespace std;

int const MAX = 10000;
int const NIL = -1;

struct Node {int p, l, r; };
struct Node T[MAX];
int n;

/* 先行順巡回 */
void preParse(int u) {
  if (u == NIL) return;
  printf(" %d", u);
  preParse(T[u].l);
  preParse(T[u].r);
}

/* 中間順巡回 */
// int j = 0;
// void inParse(int u) {
//   if (u == NIL) { printf("NIL\n"); return;};
//   j++;
//   printf("jは%d\n", j);
//   printf("いま%d\n", T[u].l);
//   inParse(T[u].l);
//   printf(" %d\n", u);
//   inParse(T[u].r);
// }



/* 後行順巡回 */
void postParse(int u) {
  if (u == NIL) return;
  postParse(T[u].l);
  postParse(T[u].r);
  printf(" %d", u);
}

int main() {
  int i, v, l, r, root;

  scanf("%d", &n);      // 節点の個数
  for (int i = 0; i < n; i++ ) {
    scanf("%d %d %d", &v, &l, &r);  // 自身の節点番号, 左の子, 右の子
    T[v].l = l;
    T[v].r = r;
    if ( l != NIL ) T[l].p = v;
    if ( r != NIL ) T[l].p = v;
  }

  for (int i = 0; i < n; i++ ) if (T[i].p == NIL ) root = i;

  printf("Preorder\n");
  preParse(root);
  printf("\n");
  printf("Inorder\n");
  inParse(root);
  printf("\n");
  printf("Postorder\n");
  postParse(root);
  printf("\n");

  return 0;
}
