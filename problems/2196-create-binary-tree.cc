/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> getNode;
    unordered_map<int, bool> isChild;

    for (auto &v : descriptions) {
      int parent = v[0], child = v[1], isLeft = v[2];

      // Create parent node if it doesn't exist
      if (getNode.count(parent) == 0) {
        getNode[parent] = new TreeNode(parent);
      }

      // Create child node if it doesn't exist
      if (getNode.count(child) == 0) {
        getNode[child] = new TreeNode(child);
      }

      // Set the child node as the left or right child of the parent
      if (isLeft) {
        getNode[parent]->left = getNode[child];
      } else {
        getNode[parent]->right = getNode[child];
      }

      // Mark the child node as having a parent
      isChild[child] = true;
    }

    // Find the root node (the node with no parent)
    TreeNode *root = nullptr;
    for (auto &v : descriptions) {
      if (!isChild[v[0]]) {
        root = getNode[v[0]];
        break;
      }
    }

    return root;
  }
};

int lowerBound(vector<int> arr, int n, int x) {
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high) {
    int mid = (low + high) / 2;
    // maybe an answer
    if (arr[mid] >= x) {
      ans = mid;
      // look for more small index on left
      high = mid - 1;

      else {
        low = mid + 1; // look for right
      }
    }

    return ans;
  }