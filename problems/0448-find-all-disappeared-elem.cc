class Solution {
public:
  /*
  first iterate throught the array and mark the value as negative, and then
  return the unmarked value.
  */
  vector<int> findDisappearedNumbers(vector<int> &nums) {

    vector<int> ans;

    // mark negative value
    for (int x : nums) {
      int currentv = abs(x);
      nums[currentv - 1] = 0 - abs(nums[currentv - 1]);
    }

    // we are done with marking the value, now just check unmarked ones.
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        ans.push_back(i + 1);
      }
    }

    return ans;
  }
};