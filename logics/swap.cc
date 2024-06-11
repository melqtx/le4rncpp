
#include <iostream>
using namespace std;

// Function having parameters as
// references
void swap(int &first, int &second) {
  int temp = first;
  first = second;
  second = temp;
}

/
  // Variables declared
  int a, b;
  cout << "enter nos to be swapped: ";
  cin >> a >> b;

  // function called
  swap(a, b);

  // changes can be seen
  // printing both variables
  cout << a << " " << b;
  return 0;
}
