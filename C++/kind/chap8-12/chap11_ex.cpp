#include <iostream>
using namespace std;

struct Person{
  int age;
  double weight;
  double height;
};

void show(Person* pP, int n);

int main()
{
  Person* pP;
  int n;

  cout << "Input how many people you want to record.\n";
  cin >> n;

  pP = new Person[n];

  for(int i=0; i < n; i++){
  cout << "Input age.\n";
  cin >> pP[i].age;
  cout << "Input weight.\n";
  cin >> pP[i].weight;
  cout << "Input height.\n";
  cin >> pP[i].height;
  }

  show(pP, n);

  delete[] pP;

  return 0;
}

void show(Person* pP, int n)
{
  for(int i; i<n; i++){
    cout << "age: " << pP[i].age << '\n' << "weight: " << pP[i].weight << '\n' << "height: " << pP[i].height << '\n';
  }
}
