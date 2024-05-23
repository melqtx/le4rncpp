//i wish i was smart enough to do this in first try.

#include <iostream>

int main() {

  int n;
  std::cout << "enter n";
  std::cin >> n;

  // main loop of patterns start here
  for (int i = n; i >= 1; i--) {
    for (int j = i; j >= 1; j--) {
      if (i == n && j == 1) {
        std::cout << j;
      } else {
        std::cout << j << " ";
      }
    }
    std::cout << std::endl;
  }
  return 0;
}

/*
5 4 3 2 1
4 3 2 1
3 2 1
2 1
1
*/
