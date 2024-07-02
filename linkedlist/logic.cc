#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};

Node *first = nullptr;

void create(int A[], int n) {
  int i;
  Node *t, *last;
  first = new Node;
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++) {
    Node *t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

int add(Node *p) {
  int sum = 0;
  while (p) {
    sum = sum + p->data;
    p = p->next;
  }
  return sum;
}

int cnt(Node *p) {
  int c = 0;
  while (p != NULL) {
    c++;
    p = p->next;
  }
  return c;
}

void display(Node *p) {
  if (p != NULL) {
    display(p->next);
    cout << p->data << " ";
  }
}

int main() {
  int A[] = {3, 5, 8, 21, 69};
  int n = sizeof(A) / sizeof(A[0]);
  create(A, n);
  display(first);
  cout << '\n';
  cout << cnt(first) << '\n';
  cout << "The sum is: " << add(first);

  return 0;
}
