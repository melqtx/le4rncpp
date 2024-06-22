#include <bits/stdc++.h>
using namespace std;
int secondlargest(int arr[], int n) {
  int largest = arr[0];
  int slargest = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > largest) {
      slargest = largest;
      largest = arr[i];
    } else if (arr[i] < largest && arr[i] > slargest) {
      slargest = arr[i];
    }
  }
  cout << slargest << '\n';
  return slargest;
}

int secondsmallest(int arr[], int n) {
  int smallest = arr[0];
  int ssmallest = INT_MAX;

  for (int i = 0; i < n; i++) {
    if (arr[i] < smallest) {
      ssmallest = smallest;
      smallest = arr[i];

    } else if (arr[i] > smallest && arr[i] < ssmallest) {
      ssmallest = arr[i];
    }
  }
  cout << ssmallest << "\n";
  return ssmallest;
}

int main() {
  int arr[30], n, i;
  cout << "Enter no of elements: ";
  cin >> n;
  cout << "Enter array elements:";
  for (i = 0; i < n; i++)
    cin >> arr[i];

  secondlargest(arr, n);
  secondsmallest(arr, n);

  cout << "The array is: \n ";
  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
