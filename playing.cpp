#include <iostream>
#include <vector>

using namespace std;
int main() {

  vector<int> coll; // vector container for integer elements
  // append elements with values 1 to 6
  for (int i = 1; i <= 6; ++i) {
    coll.push_back(i);
  }
  // print all elements followed by a space
  for (int i = 0; i < coll.size(); ++i) {
    cout << coll[i] << " ";
  }
  cout << endl;
}
