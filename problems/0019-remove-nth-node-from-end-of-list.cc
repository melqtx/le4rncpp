class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;

        ListNode* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            temp = temp->next;
            cnt++;
        }

        if (n > cnt) return head;  // Invalid case
        if (n == cnt) return head->next;  // Remove head

        int index = cnt - n;
        temp = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;
        return head;
    }
};
