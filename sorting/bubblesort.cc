#include <iostream>
using namespace std;

void sort(int A[], int n) {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (A[j] > A[j + 1]) {
        int temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
}

int main() {

  int A[] = {9, 6, 8, 5, 7, 2, 1, 3, 4};
  int n = sizeof(A) / sizeof(int);
  sort(A, n);
}