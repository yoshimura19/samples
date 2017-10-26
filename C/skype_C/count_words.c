#include <stdio.h>

#define IN 1 /* 単語の中 */
#define OUT 0 /* 単語の外 */

/* 入力中の行、単語、文字のカウント */
int main(void)
{
  int c, nl, nw, nc, state;
c
  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF){

    ++nc;
    if (c == '\n'){
      ++nl;
    }
    if (c == '' || c == '\n' || c == '\t'){
      state = OUT;}
    else if(state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}
