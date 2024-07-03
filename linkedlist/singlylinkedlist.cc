#include <iostream>
#include <string>
using namespace std;

class StringNode {
private:
  string elem;
  StringNode *next;

  friend class StringLinkedList;
};

class StringLinkedList {
public:
  StringLinkedList();
  ~StringLinkedList();
  bool empty() const;
  const string &front() const;
  void addfront(const string &e);
  void removefront();

private:
  StringNode *head;
};

// Constructor
StringLinkedList::StringLinkedList() : head(nullptr) {}

// Destructor
StringLinkedList::~StringLinkedList() {
  while (!empty()) {
    removefront();
  }
}

// Check if the list is empty
bool StringLinkedList::empty() const { return head == nullptr; }

// Get the front element
const string &StringLinkedList::front() const { return head->elem; }

// Add a new node to the front of the list
void StringLinkedList::addfront(const string &e) {
  StringNode *newNode = new StringNode;
  newNode->elem = e;
  newNode->next = head;
  head = newNode;
}

// Remove the front node from the list
void StringLinkedList::removefront() {
  if (!empty()) {
    StringNode *temp = head;
    head = head->next;
    delete temp;
  }
}

// adding an element to the front
void StringLinkedList::addfront(const string &e) {
  StringNode *v = new StringNode;
  v->elem = e;
  v->next = head;
  head = v;
}

void StringLinkedList::removefront() {
  StringNode *old = head;
  head = old->next;
  delete old;
}