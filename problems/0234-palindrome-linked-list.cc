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
    bool isPalindrome(ListNode* head) {
        stack<int> A;
        ListNode* temp = head;
        while(temp != nullptr){
            A.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            if(A.top() != temp->val)return false;
            temp = temp->next;
            A.pop();
        }
        return true;
    }
};
class Solution {
public:
    // the basic approach we are gonna use is
    // find the middle, reverse from there, then comparte both the halves.

    ListNode* reverse(ListNode* head) {
        ListNode* p = head;
        ListNode* q = nullptr;
        ListNode* r = nullptr;
        while(p) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
        return head;
    }




    bool isPalindrome(ListNode* head) {
        // base case
        if(head == nullptr && head->next == nullptr) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!= nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* half2 = reverse(slow->next);
        ListNode* half1 = head;
        while(half2 != nullptr){
            if(half1->val != half2->val) return false;
            half1 = half1->next;
            half2 = half2->next;
        }
        slow->next = reverse(slow->next);
        return true;

    }
};

