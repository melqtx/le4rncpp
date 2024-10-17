/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr) {
      ListNode *nextNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextNode;
    }

    return prev;
  }
};

// we could have used another approac as well, using an array or stack, first
// store all the values from the list into it, and then later enter the values
// back.

// you may ask why stack? well it sotres value on Last in first out basis, which
// matches here.
// we couldve used recursive approach as well, but skill issues.
class Solution {
public:
  ListNode *reverseList(ListNode *first) {
    ListNode *t = first;
    stack<int> A;
    while (t != nullptr) {
      A.push(t->val);
      t = t->next;
    }

    t = first;

    while (t != nullptr) {
      t->val = A.top();
      A.pop();
      t = t->next;
    }
    return first;
  }
};
