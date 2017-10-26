#include <iostream>
using namespace std;

static const int MAX = 36;

struct Card { char suit; int value; };  // suit絵柄

void bubbleSort(struct Card A[], int N);
void selectionSort(struct Card A[], int N);
void print(struct Card A[], int N);
bool isStable(struct Card C1[], struct Card C2[], int N);

int main()
{
  Card C1[MAX], C2[MAX];
  int N;       // データ数
  char ch;     //

  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> C1[i].suit >> C1[i].value;
  }

  for (int i = 0; i < N; i++) C2[i] = C1[i];

  bubbleSort(C1, N);
  selectionSort(C2, N);

  print(C1, N);
  cout << "Stable" << endl;   // bubbleソートは安定ソート
  print(C2, N);
  if (isStable(C1, C2, N)){
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  return 0;
}

void bubbleSort(struct Card A[], int N)
{
  for(int i = 0; i < N; i++){
    for(int j = N-1; j >= i+1; j--){
      if(A[j].value < A[j-1].value){
        Card t = A[j];
        A[j] = A[j-1];
        A[j-1] = t;
      }
    }
  }
}

void selectionSort(struct Card A[], int N)
{
  for(int i = 0; i < N; i++){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A[j].value < A[minj].value) minj = j;
    }
    Card t = A[i];
    A[i] = A[minj];
    A[minj] = t;
  }
}

// バブルソートと選択ソートの結果を比較
bool isStable(struct Card C1[], struct Card C2[], int N)
{
  for(int i = 0; i < N; i++){
    if(C1[i].suit != C2[i].suit)
      return false;
  }
  return true;
}

void print(struct Card A[], int N)
{
  for(int i = 0; i < N; i++){
    if(i > 0) cout << ' ';
    cout << A[i].suit << A[i].value;
      }
  cout << endl;
}

