// took break from learning due to exams, and i forgot how to do shit; took me an entire day to figure basic shit out.


#include <bits/stdc++.h>

using namespace std;

int main() {

  int rows, cols;
  cin >> rows;
  cin >> cols;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
        cout << "* ";
      else
        cout << "  ";
    }
    cout << endl;
  }

  return 0;
}

// oh this prints hollow square.
