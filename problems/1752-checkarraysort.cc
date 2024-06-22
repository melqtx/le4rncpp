// first approach, can be used
// well this can be used, but this fails a test case, hmm i need to think of
// something better.
class Solution {
public:
  bool check(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        return false;
      }
    }
    return true;
  }
};

// a better but complex
//  This checks if the array is sorted in non-decreasing order with at most one
//  rotation. It counts the number of times nums[i] < nums[i-1]. If this happens
//  more than once, it returns false. If it happens exactly once, it also checks
//  if nums[0] < nums.back() to ensure proper rotation
// okay

class Solution {
public:
  bool check(vector<int> &nums) {
    int count = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) {
        count++;
      }
    }
    if (count > 1)
      return false;
    if (count == 1 && nums[0] < nums.back())
      return false;
    return true;
  }
};
