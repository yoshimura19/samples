#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  cout << "こんにちは！" << endl;
  cout << "さようなら！" << endl;

  cout << "10を10進数で表記すると" << dec << 10 << "です。\n";
  cout << "10を8進数で表記すると" << oct << 10 << "です。\n";
  cout << "12を8進数で表記すると" << 12 << "です。\n";        //指定しなかった場合は、最後にしていした書式が有効
  cout << "12を16進数で表記すると" << hex << 10 << "です。\n";


  for (int i=0; i<=10; i++){
    cout << setw(3) << i;
  }
  cout << '\n';

  return 0;
}
