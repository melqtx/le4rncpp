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
