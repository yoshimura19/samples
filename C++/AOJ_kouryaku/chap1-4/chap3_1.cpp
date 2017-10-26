#include <iostream>
using namespace std;

static const int MAX = 100;

void insertionSort(int array[], int N); // 挿入ソート
void trace(int array[], int N);  // Output用


int main()
{
  int N;  // 入力データ数
  int A[MAX];

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  trace(A, N);
  insertionSort(A, N);

  return 0;
}

// 挿入ソートアルゴリズム
void insertionSort(int A[], int N)
{
  for(int i = 1; i < N; i++){
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    trace(A, N);
  }
}
void trace(int array[], int N)
{
  for(int i = 0; i < N; i++){
    if(i >= 1) cout << ' ';
    cout << array[i];
  }
  cout << endl;
}
