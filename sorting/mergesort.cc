#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int h) {
  int temp[69];
  int i, j, k = 0;
  i = l;
  j = m + 1;

  while (i <= m && j <= h) {
    if (a[i] <= a[j]) {
      temp[k++] = a[i++];
    } else {
      temp[k++] = a[j++];
    }
  }
  while (i <= m) {
    temp[k++] = a[i++];
  }
  while (j <= h) {
    temp[k++] = a[j++];
  }
  for (i = l, j = 0; i <= h; i++, j++) {
    a[i] = temp[j];
  }
}

void mergesort(int a[], int l, int h) {
  if (l >= h)
    return;
  int mid = (l + h) / 2;
  mergesort(a, l, mid);
  mergesort(a, mid + 1, h);
  merge(a, l, mid, h);
}

int main() {
  int a[30], n, i;
  cout << "Enter no of elements: ";
  cin >> n;
  cout << "Enter array elements:";
  for (i = 0; i < n; i++)
    cin >> a[i];
  mergesort(a, 0, n - 1);
  cout << "\nSorted array is :";
  for (i = 0; i < n; i++)
    cout << a[i] << " ";
  return 0;
}