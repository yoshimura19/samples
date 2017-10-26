#include <iostream>
using namespace std;

static const int MAX = 100;

int bubbleSort(int A[], int N);  // 戻り値は交換回数

// バブルソート

int main()
{
  int N;   // データ数
  int A[MAX];

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  // 出力
  int count = bubbleSort(A, N);
  for(int i = 0; i < N; i++){
    if(i >= 1) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << count << endl;

  return 0;
}

int bubbleSort(int A[], int N)
{
  int i, count = 0;
  int flag = 1;

  while(flag){
    flag = 0;
    for(int j = N-1; j >= i + 1; j--){
      if(A[j] < A[j-1]){
        int tmp = A[j-1];   // Can write just swap(A[j], A[j-1])
        A[j-1] = A[j];
        A[j] = tmp;
        flag = 1;
        count++;
      }
    }
    i++;
  }
  return count;
}
