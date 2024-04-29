
//=========================================

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

//======================================================

#include <iostream>

int main() {

  int n;
  std::cout << n;
  std::cin >> n;

  for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= i; j++) {
      std::cout << "* ";
    }

    std::cout << '\n';
  }

  for (int i = 1; i <= n; i++) {

    for (int j = i; j < n; j++) {
      std::cout << "* ";
    }

    std::cout << '\n';
  }

  return 0;
}

//======================================================

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

* /