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