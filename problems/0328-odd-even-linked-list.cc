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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        vector<int> a;
        ListNode* temp = head;
        while(temp != nullptr && temp->next != nullptr){
            a.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) a.push_back(temp->val);
        temp = head->next;
        while(temp != nullptr && temp->next != nullptr){
            a.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) a.push_back(temp->val);
        int i = 0; 
        temp = head;
        while(temp){
            temp->val = a[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
        
        return head;
    }
};

// i spend half an hourlooking for != fuck my life
