/*
printing this was pain in the ass
but okay it was fun; my logic might suck, but atleast im practical about it.


5 5 5 5 5 5 5 5 5
5 4 4 4 4 4 4 4 5
5 4 3 3 3 3 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 2 1 2 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 3 3 3 3 4 5
5 4 4 4 4 4 4 4 5
5 5 5 5 5 5 5 5 5

*/

#include <iostream>
using namespace std;

int main() {

  int n;
  cout << n;
  cin >> n;

  for (int i = n; i > 0; i--) {

    for (int j = n; j > i; j--) {

      cout << j << " ";
    }

    for (int j = 0; j < (2 * i) - 1; j++) {

      cout << i << " ";
    }

    for (int j = i; j < n; j++) {

      cout << j + 1 << " ";
    }

    cout << endl;
  }

  for (int i = 0; i < n - 1; i++) {

    for (int j = n; j > i + 2; j--) {

      cout << j << " ";
    }

    for (int j = 0; j < (2 * i) + 3; j++) {

      cout << i + 2 << " ";
    }

    for (int j = i + 3; j <= n; j++) {

      cout << j << " ";
    }

    cout << endl;
  }
  return 0;
}