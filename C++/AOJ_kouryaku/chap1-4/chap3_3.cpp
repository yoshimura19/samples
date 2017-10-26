#include <iostream>
using namespace std;

static const int MAX = 100;

int selectionSort(int A[], int N);  // 戻り値は交換回数

int main()
{
  int N;
  int A[100];

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  int count = selectionSort(A, N);
  for(int i = 0; i < N; i++){
    if(i >= 1) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << count << endl;

  return 0;
}

int selectionSort(int A[], int N)
{
  int count = 0;

  for(int i = 0; i < N; i++){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A[j] < A[minj]) minj = j;
    }
    swap(A[i], A[minj]);
    if(i != minj) count++;
  }
  return count;
}
