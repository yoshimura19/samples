#include <iostream>
using namespace std;

double avg(int array[]);

int main()
{
  int i;
  int test[5];

  cout << "Input the scores of 5 persons\n";
  for(i=0;i<5;i++){
    cin >> test[i];
  }
  double ans = avg(test);
  cout << "The average of 5 persons is " << ans << ".\n";

  return 0;
}

double avg(int array[])
{
  int i;
  double sum=0;

  for(i = 0; i < 5; i++){
    sum += array[i];
  }
  return sum / 5;
}
