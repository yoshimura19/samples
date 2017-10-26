#include <iostream>
using namespace std;

int main()
{
  int i,j;
  int score, sum=0;

  /* exercise 1 */
  cout << "Output odd numbers between 1 to 10.\n";
  for(i = 1; i <= 10; i++){
    if(i % 2 == 0){
      cout << i << '\n';
    }
  }

  /* exercise 2 */
  cout << "Input test scores. (End with 0)\n";
  do{
    cin >> score;
    sum += score;
  } while(score != 0);
  cout << "The sum of scores is " << sum << ".\n";


  /* exercise 3 */
  for(i=1; i<=10; i++){
    for(j=1; j<=i; j++){
      cout << "*";
    }
    cout << '\n';
  }

  return 0;
}
