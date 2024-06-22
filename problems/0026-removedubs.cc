// brute force approach, take a set, and store init.
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    set<int> set;
    for (int i = 0; i < nums.size(); i++) {
      set.insert(nums[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x : set) {
      nums[j++] = x;
    }
    return k;
  }
};

// second two pointer approach
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int i = 0;
    int n = nums.size();
    for (int j = 0; j < n; j++) {
      if (nums[i] != nums[j]) {
        nums[i + 1] = nums[j];
        i++;
      }
    }
    return i + 1;
  }
};