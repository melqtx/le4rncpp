class Solution {
public:
  int search(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target)
        return mid;

      // left sorted
      if (nums[low] <= nums[mid]) {
        if (nums[low] <= target && target <= nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }

      // right sorted
      if (nums[mid] <= target && target <= nums[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }
};