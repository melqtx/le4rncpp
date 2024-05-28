#include <iostream>

void pypart(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      std::cout << i << " ";
    }
    std::cout << '\n';
  }
}
int main() {
  int count;
  std::cout << "enter the number: ";
  std::cin >> count;
  pypart(count);
  return 0;
}
