// lmao just found out that this triangle is called floyds triangle, idk why tho, dm me the reason.

#include <iostream>

int main() {
  int value = 1;
  int n;
  std::cout << "enter n: ";
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      std::cout << value << " ";
      value++;
    }
    std::cout << '\n';
  }
  return 0;
}


// this consumed a lot of my time, and this was the simplest of all patterns.
