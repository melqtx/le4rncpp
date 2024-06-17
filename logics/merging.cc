#include <iostream>
#include <vector>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[]) {
  int i, j, k;
  i = j = k = 0;

  while (i < n && j < m) {
    if (arr1[i] < arr2[j]) {
      arr3[k++] = arr1[i++];
    } else {
      arr3[k++] = arr2[j++];
    }
  }
  while (i < n) {
    arr3[k++] = arr1[i++];
  }
  while (j < m) {
    arr3[k++] = arr2[j++];
  }
}

void print(int ans[], int n) {
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}

int main() {
  int arr1[5] = {2, 4, 6, 8, 10};
  int arr2[5] = {1, 3, 5, 7, 9};

  int arr3[10];

  merge(arr1, 5, arr2, 5, arr3);
  print(arr3, 10);
  return 0;
}
