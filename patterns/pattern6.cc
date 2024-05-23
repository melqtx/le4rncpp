// this prints your mom

#include <iostream>

int main() {
    int n;
    std::cout << "Enter the size of the square: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n) {
                std::cout << "* ";
            } else {
                if (j == 1 || j == n) {
                    std::cout << "* ";
                } else {
                    std::cout << "  ";
                }
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
