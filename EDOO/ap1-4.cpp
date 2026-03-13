// A program containing errors!
#include <iostream> 
#include <string>
#include <stdlib.h>

void srand(unsigned int seed);

int main() {
  std::string message = "\nLearn from your mistakes!";
  std::cout << message << std::endl;
  int len = message.length();
  std::cout << "Length of the string: " << len << std::endl;
  // And a random number in addition:
  int a, b;
  srand(12);
  b = rand();
  std::cout << "\nRandom number: " << b << std::endl;
 return 0;
}
