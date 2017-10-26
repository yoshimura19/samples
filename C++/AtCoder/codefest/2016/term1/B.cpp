#include <iostream>
using namespace std;

// 仲良しうさぎ Friendly Rabbits

int main()
{
  int N;
  cin >> N;

  int a[10002];
  for (int i = 1; i <= N; i++) {   // 1-originated
    cin >> a[i];
    cout << i << "番目" << a[i] << " ";
  } cout << endl;


  int pair = 0;
  for (int i = 1; i <= N; i++) {
    if (a[a[i]] == i) pair++;
  }

  cout << pair / 2 << endl;

  return 0;
}
