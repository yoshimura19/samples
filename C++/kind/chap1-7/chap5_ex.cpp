#include <iostream>
using namespace std;

int main()
{
  int num, num1, num2;
  int odd_even;
  int grade;

  /* exercise 1 */
  cout << "Input an integer.:";
  cin >> num;

  // conditional operator
  (num % 2 != 0) ? cout << num << " is an odd number.\n" : cout << num << " is an even number.\n";

  /* another way */
  // cout << "Input an integer.:";
  // cin >> num;
  // if (num % 2 != 0){
  //   cout << num << " is an odd number.\n";
  // }
  // else{
  //   cout << num << " is an even number.\n";
  // }

  /* exercise 2 */
  cout << "Input two integers.:";
  cin >> num1;
  cin >> num2;
  if(num1 > num2){
    cout << num1 << " is larger than " << num2 << ".\n";
  } else if(num2 > num1){
    cout << num2 << " is larger than " << num1 << ".\n";
  } else{
    cout << "both numbers are the same.\n";
  }

  /* exercise 3 */
  cout << "Input the grade>";
  cin >> grade;

  switch(grade){
  case 1:
    cout << "Your grade is " << grade << " . You should study hard.\n";
    break;
  case 2:
    cout << "Your grade is " << grade << " . You should study hard.\n";
    break;
  case 3:
    cout << "Your grade is " << grade << " . You should study hard.\n";
    break;
  case 4:
    cout << "Your grade is " << grade << " . You should study hard.\n";
    break;
  case 5:
    cout << "Your grade is " << grade << " . You should study hard.\n";
    break;
  }

  return 0;
}
