class Solution {
public:
  void deleteNode(ListNode *node) {
    // Check if the node to be deleted is the last node
    if (node->next == nullptr) {
      delete node;
      return;
    }

    // Copy the value of the next node to the current node
    node->val = node->next->val;

    // Store the next node of the node to be deleted
    ListNode *temp = node->next;

    // Update the next pointer of the current node to skip the next node
    node->next = node->next->next;

    // Delete the next node
    delete temp;
  }
};