// stl/array1.cpp
#include <array>
#include <iostream>
#include <string>

using namespace std;
int main() {
  // array container of 5 string elements:
  array<string, 5> coll = {"hello", "world", "im", "stupid"};
  // print each element with its index on a line
  for (int i = 0; i < coll.size(); ++i) {
    cout << i << ": " << coll[i] << endl;
  }
}