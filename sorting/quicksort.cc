#include <bits/stdc++.h>
using namespace std;

int pindex(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j) {
    while (arr[i] <= pivot && i <= high - 1) {
      i++;
    }

    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void qs(vector<int> &arr, int low, int high) {
  if (low < high) {
    int partition = pindex(arr, low, high);
    qs(arr, low, partition - 1);
    qs(arr, partition + 1, high);
  }
}

vector<int> quickSort(vector<int> arr) {
  qs(arr, 0, arr.size() - 1);
  return arr;
}

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Before Using quick Sort: " << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  arr = quickSort(arr);
  cout << "After Using quick sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  return 0;
}