/*
okay this took me an entire hour, ikr this code couldve been more efficient but let it be. if it works it works.



*                         *
* *                     * *
* * *                 * * *
* * * *             * * * *
* * * * *         * * * * *
* * * * * *     * * * * * *
* * * * * * * * * * * * * *
* * * * * *     * * * * * *
* * * * *         * * * * *
* * * *             * * * *
* * *                 * * *
* *                     * *
*                         *

 */

#include <iostream>

int main() {

  int n;
  std::cout << "enter n: ";
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      std::cout << "* ";
    }
    for (int j = i; j < n; j++) {
      std::cout << "  ";
    }
    for (int j = i; j < n; j++) {
      std::cout << "  ";
    }
    for (int j = 1; j <= i; j++) {
      std::cout << "* ";
    }

    std::cout << '\n';
  }

  for (int i = 1; i < n; i++) {
    for (int j = i; j < n; j++) {
      std::cout << "* ";
    }
    for (int j = 1; j <= i; j++) {
      std::cout << "  ";
    }
    for (int j = 1; j <= i; j++) {
      std::cout << "  ";
    }
    for (int j = i; j < n; j++) {
      std::cout << "* ";
    }
    std::cout << '\n';
  }
}


///__________________________________________________________


#include <iostream>

int main() {
  int n;
  std::cout << "enter n: ";
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      std::cout << j << " ";
    }
    for (int j = i; j < n; j++) {
      std::cout << "  ";
    }
    for (int j = i; j < n; j++) {
      std::cout << "  ";
    }
    for (int j = 1; j <= i; j++) {
      std::cout << n - i + j << " ";
    }

    std::cout << '\n';
  }

  for (int i = 1; i < n; i++) {
    for (int j = i; j < n; j++) {
      std::cout << j + 1 << " ";
    }
    for (int j = 1; j <= i; j++) {
      std::cout << "  ";
    }
    for (int j = 1; j <= i; j++) {
      std::cout << "  ";
    }
    for (int j = i; j < n; j++) {
      std::cout << n - i + j + 1 << " ";
    }
    std::cout << '\n';
  }

  return 0;
}
