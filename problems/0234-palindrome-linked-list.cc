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
    ListNode* reverse(ListNode* head) {
        ListNode* p = head;
        ListNode* q = nullptr;
        ListNode *r = nullptr;
        while(p){
            r = q;
            q = p; 
            p = p->next;
            q->next = r;
        }
        head = q;
        return head;
    }


    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find the end of first half and reverse second half
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverse(slow->next);
        ListNode* firstHalf = head;

        // Compare the two halves
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        slow->next = reverse(slow->next);

        return true;
    }
};
