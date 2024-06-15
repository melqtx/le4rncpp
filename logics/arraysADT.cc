#include <iostream>
using namespace std;

struct Array {
  int A[20];
  int length;
  int size;
};

void insert(Array *arr, int index, int value) {
  if (index >= 0 && index <= arr->length) {
    for (int i = arr->length; i > index; i--) {
      arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = value;
    arr->length++;
  }
}

int Delete(Array *arr, int index) {
  int x = 0;
  if (index >= 0 && index < arr->length) {
    x = arr->A[index];
    for (int i = index; i < arr->length - 1; i++) {
      arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
    return x;
  }
  return 0;
}

int Min(Array arr) {
  int min = arr.A[0];
  for (int i = 0; i < arr.length; i++) {
    if (arr.A[i] < min) {
      min = arr.A[i];
    }
  }
  return min;
}

int Max(Array arr) {
  int max = arr.A[0];
  for (int i = 0; i < arr.length; i++) {
    if (arr.A[i] > max) {
      max = arr.A[i];
    }
  }
  return max;
}

int Sum(Array arr) {
  int total = 0;
  for (int i = 0; i < arr.length; i++) {
    total = total + arr.A[i];
  }
  return total;
}

float Avg(Array arr) { return (float)Sum(arr) / arr.length; }

void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int LSearch(Array *arr, int key) {
  for (int i = 0; i < arr->length; i++) {
    if (key == arr->A[i]) {
      swap(&arr->A[i], &arr->A[0]);
      return i;
    }
  }
  return -1;
}

// done using loops
int BSearch1(Array arr, int key) {
  int l, h;
  l = 0;
  h = arr.length - 1;
  while (l <= h) {
    int mid = (l + h) / 2;
    if (key == arr.A[mid]) {
      return mid;
    } else if (key <= arr.A[mid]) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}

// done using recursion calls
int BSearch2(Array arr, int l, int h, int key) {
  int mid;
  while (l <= h) {
    mid = l + (h - 1) / 2;
    if (key == arr.A[mid]) {
      return mid;
    } else if (key < arr.A[mid]) {
      return (arr, l, mid - 1, key);
    } else {
      return (arr, mid + 1, h, key);
    }
  }
  return -1;
}

void Display(Array *arr) {
  int i;
  cout << "elements are:";
  for (i = 0; i < arr->length; i++) {
    cout << " " << arr->A[i];
  }
}

int main() {
  Array arr = {
      {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30}, 15, 10};
  arr.length = 15;
  insert(&arr, 0, 0);
  //*Delete(&arr, 3);*//
  Display(&arr);
  cout << '\n';
  return 0;
}
