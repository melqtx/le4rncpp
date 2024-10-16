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
    ListNode* deleteDuplicates(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode dummy(0);  // Dummy node to handle cases where head needs to be removed
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* p = head;
        ListNode* q = head->next;
        
        while (q != nullptr) {
            bool duplicateFound = false;
            
            while (q != nullptr && p->val == q->val) {
                duplicateFound = true;
                ListNode* temp = q;
                q = q->next;
                delete temp;
            }
            
            if (duplicateFound) {
                prev->next = q;
                delete p;
                p = q;
                if (q != nullptr) q = q->next;
            } else {
                prev = p;
                p = q;
                q = q->next;
            }
        }
        
        return dummy.next;
    }
};
