#include <bits/stdc++.h>
using namespace std;

int hashArray[100000000];  // 1e7 globally, if you wanna declare locally the limit is 1e6.

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // precompute

  for (int i = 0; i < n; i++) {
    hashArray[arr[i]] += 1;
  }

  int q;
  cout << "Enter queries: ";
  cin >> q;
  while (q--) {
    int number;
    cin >> number;
    cout << "Number of " << number << " in the array: " << hashArray[number] << '\n';
  }
}
