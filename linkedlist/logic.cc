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

int rcnt(Node *p) {
  if (p != NULL)
    return rcnt(p->next) + 1;
  else
    return 0;
}

int max(Node *p) {
  int m = INT_MIN;
  while (p) {
    if (p->data > m) {
      m = p->data;
    }
    p = p->next;
  }
  return m;
}

int rmax(Node *p) {
  int x = 0;
  if (p == 0) {
    return INT_MIN;
  } else {
    x = rmax(p->next);
    if (x > p->data)
      return x;
    else
      return p->data;
  }
}

// i dont get this shit
int rmax2(Node *p) {
  return (p == NULL) ? INT_MIN
                     : ((max(p->next) > p->data) ? max(p->next) : p->data);
}

int rmin(Node *p) {
  int x = 0;
  if (p == 0) {
    return INT_MAX;
  } else {
    x = rmin(p->next);
    if (x < p->data)
      return x;
    else
      return p->data;
  }
}

/*Node *search(Node *p, int key) {
  Node *q = NULL;
  while (p != NULL) {
    if (key == p->data) {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
} */

Node *search(Node *p, int key) {
  Node *q = nullptr;
  while (p != nullptr) {
    if (key == p->data) {
      if (q == nullptr) {
        // The node to be moved is the head node
        first = p->next;
      } else {
        q->next = p->next;
      }
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return nullptr;
}

Node *RSearch(Node *p, int key) {
  if (p == nullptr) {
    return nullptr;
  }
  if (key == p->data) {
    return p;
  }
  return RSearch(p->next, key);
}

void display(Node *p) {
  if (p != NULL) {
    display(p->next);
    cout << p->data << " ";
  }
}

int main() {
  int A[] = {67, 2,  89, 3,  59, 5,  73, 7,  83, 11, 13, 17, 19,
             23, 29, 31, 37, 41, 43, 47, 53, 61, 71, 79, 96};
  int n = sizeof(A) / sizeof(A[0]);
  create(A, n);
  display(first);
  cout << '\n';
  cout << "The length is: " << rcnt(first) << '\n';
  cout << "The sum is: " << add(first) << '\n';
  cout << "The max integer is: " << rmax2(first) << '\n';
  cout << "The min integer is: " << rmin(first) << '\n';
  if (RSearch(first, 71))
    cout << "KEY FOUND";
  else
    cout << "KEY NOT found";

  display(first);
  return 0;
}