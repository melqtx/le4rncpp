#include <iostream>

int main() {
  char startChar = 'A';
  int n;
  std::cout << n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << static_cast<char>(startChar + j);
    }
    std::cout << std::endl;
    startChar++;
  }

  return 0;
}


/*
ABCDE
BCDEF
CDEFG
DEFGH
EFGHI
*/
