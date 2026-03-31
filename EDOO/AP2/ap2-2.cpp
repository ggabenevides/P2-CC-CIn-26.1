#include <iostream>
#include<iomanip>
using namespace std;

int main() {
  char ch;
  string word;
  cout << "Let's go! Press the return key: "; 
  cin >> ch;
  cout << "Enter a word containing three characters at most: ";
  cin >> setprecision(3) >> word;
  cout << "Your input: " << ch << endl;
  return 0;
}
