#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};

Node *first = nullptr;
Node *second = nullptr;
Node *third = nullptr;

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

void create2(int A[], int n) {
  int i;
  Node *t, *last;
  second = new Node;
  second->data = A[0];
  second->next = NULL;
  last = second;

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

void Linsert(Node *p, int data) { // inserting at the last position
  Node *t = new Node;
  Node *last = nullptr;

  t->data = data;
  t->next = nullptr;
  if (p == nullptr) {
    p = last = t;
  } else {
    last->next = t;
    last = t;
  }
}

void SortedInsert(Node *p, int x) {
  Node *t = new Node;
  Node *q = nullptr;

  t->data = x;
  t->next = nullptr;

  if (first == nullptr) {
    first = t;
  } else {
    while (p && p->data < x) {
      q = p;
      p = p->next;
    }
    if (p == first) {
      t->next = first;
      first = t;
    } else {
      t->next = q->next;
      q->next = t;
    }
  }
}

void Insert(Node *p, int index, int x) {
  Node *t;
  if (index < 0 || index > cnt(p)) {
    return;
  }
  t = new Node;
  t->data = x;

  if (index == 0) {
    t->next = first;
    first = t;

  } else {
    for (int i = 0; i < index - 1; i++) {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

/*void del(Node *p) {
  //node *p = first
  first = first->next;
  int x = p->data;
  delete p;
}*/

int autodel(Node *p, int index) {
  Node *q;
  int x = -1;
  if (index < 1 || index > cnt(p)) {
    return x;
  }

  if (index == 1) {
    q = first;
    x = first->data;
    first = first->next;
    delete q;
    return x;
  } else {
    for (int i = 0; i < index - 1; i++) {
      q = p;
      p = p->next;
    }
    q = p->next;
    x = q->data;
    p->next = q->next;
    delete q;
    return x;
  }
}
/*int reverse(Node *p) {
  Node *temp = p;
  stack<int> st;

  while (temp != nullptr) {
    st.push(temp->data);
    temp = temp->next;
  }

  temp = p;
  while (temp != nullptr) {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return true;
} */

void Reverse1(Node *p) {
  int *A, i = 0;
  Node *q = p;
  int size = cnt(p);
  A = new int[size];

  // Store the values of the linked list in the array A
  while (q != nullptr) {
    A[i++] = q->data;
    q = q->next;
  }

  q = p;
  i = size - 1;
  // Assign the values from the array A back to the linked list in reverse order
  while (q != nullptr) {
    q->data = A[i--];
    q = q->next;
  }
}

void Reverse2(Node *p) {
  Node *q = nullptr, *r = nullptr;
  while (p != nullptr) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

void Reverse3(Node *p, Node *q) {
  if (p != nullptr) {
    Reverse3(p->next, p);
    p->next = q;
  } else {
    first = q;
  }
}

bool issort(Node *p) {
  int x = INT_MIN;

  while (p != nullptr) {
    if (p->data < x) {
      return false;
    }
    x = p->data;
    p = p->next;
  }
  return true;
}

void findubs(Node *p) {
  Node *q = first->next;
  while (q != nullptr) {
    if (p->data != q->data) {
      p = q;
      q = q->next;
    } else {
      p->next = q->next;
      delete q;
      q = p->next;
    }
  }
}

void findubs2(Node *p) {
  while (p != nullptr && p->next != nullptr) {
    if (p->data != p->next->data) {
      p = p->next;
    } else {
      Node *temp = p->next;
      p->next = p->next->next;
      delete temp;
    }
  }
}

void concat(Node *p, Node *q) {
  third = p;
  if (p == nullptr) {
    return;
  }

  while (p->next != nullptr) {
    p = p->next;
  }
  p->next = q;
}
// learn again [];
void merge(Node *p, Node *q) {
  Node *last;
  if (p->data < q->data) {
    third = last = p;
    p = p->next;
    third->next = nullptr;
  } else {
    third = last = q;
    q = q->next;
    third->next = nullptr;
  }

  while (p && q) {
    if (p->data < q->data) {
      last->next = p;
      last = p;
      p = p->next;
      last->next = nullptr;
    } else {
      last->next = q;
      last = q;
      q = q->next;
      last->next = nullptr;
    }
  }
  if (p != nullptr) {
    last->next = p;
  } else {
    last->next = q;
  }
}

void display(Node *p) {
  if (p != NULL) {
    cout << p->data << " ";
    display(p->next);
  }
}

int isLoop(Node *f) {
  Node *p, *q;
  p = q = f;

  do {
    p = p->next;
    q = q->next;
    q = q ? q->next : q;
  } while (p && q && p != q);
  if (p == q)
    return 1;
  else
    return 0;
}

int main() {
  int A[] = {10, 20, 30, 40, 50, 60};
  // int B[] = {5, 15, 25, 35, 45, 55, 65, 75, 85, 95};
  // int k = sizeof(B) / sizeof(B[0]);
  int n = sizeof(A) / sizeof(A[0]);

  create(A, n);

  Node *t1, *t2;
  t1 = first->next->next->next;
  t2 = first->next->next->next->next->next;
  // t2->next = t1;

  if (isLoop(first))
    cout << " it is a loop";
  else
    cout << "not a loop bitch";

  // autodel(first, 0);

  return 0;
}
