class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> ans = {-1, -1};
    if (nums.empty()) {
      return ans;
    }
    int n = nums.size(), l = 0, h = n - 1;
    while (l < h) {
      int m = l + (h - l) / 2;
      if (nums[m] < target) {
        l = m + 1;
      } else {
        h = m;
      }
    }
    if (nums[l] != target) {
      return ans;
    }
    ans[0] = l;
    h = n - 1;
    while (l < h) {
      int m = l + (h - l + 1) / 2;
      if (nums[m] > target) {
        h = m - 1;
      } else {
        l = m;
      }
    }
    ans[1] = l;
    return ans;
  }
};