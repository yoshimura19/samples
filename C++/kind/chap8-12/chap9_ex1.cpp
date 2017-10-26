#include <iostream>
using namespace std;

int max(int x[]);

int main()
{
  int score[5];

  cout << "Input test scores:\n";
  for(int i=0; i<5; i++){
    cin >> score[i];
  }

  cout << "The max value is " << max(score) << ".\n";

  return 0;
}

int max(int x[])
{
  int max_value=0;
  for(int i = 0; i < 5; i++){
    if(x[i] >= max_value){
      max_value = x[i];
    }
  }
  return max_value;
}
