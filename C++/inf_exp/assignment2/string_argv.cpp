#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
  cout << "引数の個数 = " << argc << endl;
  for (int i; i < argc; i++) {
    cout << i << "番目の引数 = " << argv[i] << endl;
  }
  return 0;
}
