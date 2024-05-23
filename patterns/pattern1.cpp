#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//this took me an entire day; yes it did, im dumb
void check(int i, int j, int first, int last, int n) {
  if (n >= 1) {
    if (i == first || i == last || j == first || j == last)
      printf("%d ", n);
    else
      check(i, j, first + 1, last - 1, n - 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int rows = 2 * n - 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      check(i, j, 0, rows - 1, n);
    }
    printf("\n");
  }
  return 0;
}



// i found a better approach for this; might not be optimal but it works.

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


// this prints your mom
