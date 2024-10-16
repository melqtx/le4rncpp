/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;

        do {
            slow = slow->next;
            fast = fast->next;
            fast = fast ? fast->next : fast;// we did fast == fast just to check if it is still valid or it became nullptr
        } while (slow && fast && slow != fast);

        return (slow == fast);
    }
};
