#include <iostream>
using namespace std;

struct Array {
  int A[25];
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

void Rev1(Array *arr) {
  int *B = new int[arr->length];
  for (int i = 0; i < arr->length; i++) {
    B[i] = arr->A[arr->length - 1 - i];
  }
  for (int i = 0; i < arr->length; i++) {
    arr->A[i] = B[i];
  }
  delete[] B; // Deallocate the memory allocated for B
}

void Rev2(Array *arr) {
  int i, j;
  int count = 0;
  for (i = 0, j = arr->length - 1; i < j; i++, j--) {
    swap(arr->A[i], arr->A[j]);
    count++;
  }
}

/*
idk how this works, will figure out later.

void Rev3(Array arr, int start, int end) {
 if (start >= end) {
    return;
  }
  swap(arr.A[start], arr.A[end]);
  Rev3(arr, start + 1, end - 1);
}

void RotateRev(Array arr, int d) {
  int n = arr.length;

  Rev3(arr, 0, d - 1);
  Rev3(arr, d, n - 1);
  Rev3(arr, 0, n - 1);
}
*/

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
// inserting in ana sorted array
void insert2(Array *arr, int x) {
  if (arr->length == arr->size) {
    return;
  }
  int i = arr->length - 1;

  while (i >= 0 && arr->A[i] > x) {
    arr->A[i + 1] = arr->A[i];
    i--;
  }

  arr->A[i + 1] = x;
  arr->length++;
}

bool isSort(Array arr) {
  for (int i = 0; i < arr.length - 1; i++) {
    if (arr.A[i] > arr.A[i + 1])
      return false;
  }
  return true;
}

void Rearr(Array *arr2) {
  int i = 0;
  int j = arr2->length - 1;

  while (i < j) {
    while (i < arr2->length &&
           arr2->A[i] <
               0) { // this tells us about the array how long will it work.
      i++;
    }
    while (j >= 0 && arr2->A[j] >= 0) {
      j--;
    }
    if (i < j) {
      swap(&arr2->A[i], &arr2->A[j]);
    }
  }
}

void Display(Array *arr2) {
  int i;
  cout << "Elements are:";
  for (i = 0; i < arr2->length; i++) {
    cout << " " << arr2->A[i];
  }
}

void Merge(Array arr1, Array arr2) {
  int i, j, k;
  i = j = k = 0;
  int *arr3 = new int[arr1.length + arr2.length];
  while (i < arr1.length && j < arr2.length) {
    if (arr1.A[i] < arr2.A[j]) {
      arr3[k++] = arr1.A[i++];
    } else {
      arr3[k++] = arr2.A[j++];
    }
  }
  // Copy the remaining elements from arr1, if any
  while (i < arr1.length) {
    arr3[k++] = arr1.A[i++];
  }
  // Copy the remaining elements from arr2, if any
  while (j < arr2.length) {
    arr3[k++] = arr2.A[j++];
  }
}
int main() {

  Array arr1 = {{2, 4, 6, 8, 10}, 10, 5};
  Array arr2 = {{1, 3, 5, 7, 9}, 10, 5};
  Array *arr3 = {0};

  // Array arr = {{2, 4, 6, 8, 10, 12, 14, 18, 20, 22, 24, 26, 28, 30}, 14, 25};
  // Array arr2{{-5, 10, -2, 7, 0, -8, 15, -12, 3, -6, 9, -4, 1, -10, 6}, 15,
  // 15};

  // Rev2(&arr);
  //   insert(&arr, 7, 16);
  //  insert2(&arr, 16);
  //  cout << isSort(arr) << '\n';
  //  Rearr(&arr2);
  Display(&arr);
  cout << endl;

  return 0;
}
