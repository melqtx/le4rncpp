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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // Create two pointers: 'lead' and 'follow'
    ListNode *lead = head;
    ListNode *follow = head;

    // Move the 'lead' pointer n steps ahead
    for (int i = 0; i < n; i++) {
      lead = lead->next;
    }

    // If 'lead' is null, it means we need to remove the head node
    if (!lead) {
      return head->next;
    }

    // Move both 'lead' and 'follow' pointers until 'lead' reaches the end
    while (lead->next) {
      lead = lead->next;
      follow = follow->next;
    }

    // Remove the nth node from the end by skipping it
    follow->next = follow->next->next;

    // Return the modified list
    return head;
  }
};