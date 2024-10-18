
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return head->next;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while(fast != nullptr and fast->next != nullptr){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }
};


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return head->next;
        ListNode* fast = head;
        ListNode* slow = head;
        fast = fast->next->next;
       // ListNode* prev = head;
        while(fast != nullptr and fast->next != nullptr){
            fast = fast->next->next;
            //prev = slow;
            slow = slow->next;
        }
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;
        //prev->next = slow->next;
        //delete slow;
        return head;
    }
};
