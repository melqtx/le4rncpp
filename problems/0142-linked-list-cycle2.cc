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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp){
            if(mpp.count(temp) != 0) return temp;
            mpp[temp] = 1;
            temp = temp->next;
        }
        return nullptr;
    }
};
