#include <iostream>
using namespace std;

void swap(float *p1, float *p2) {
  float temp; // it was a pointer, but it was pointing to an empty memory slot. it has to be a regular variable first and then you assign a pointer to it
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

int main() {
  float x = 2.1;
  float y = 3.2;

  swap(&x, &y);
  cout << "x = " << x << ", y = " << y << endl;

  return 0;
}