class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;

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
  }

  return -1;
}
}
;

// this is the brute fore approach, i feel linear search was wayy to slow.

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;

      // if mid points the target
      if (nums[mid] == target)
        return mid;

      // if left part is sorted:
      if (nums[low] <= nums[mid]) {
        if (nums[low] <= target && target <= nums[mid]) {
          // element exists:
          high = mid - 1;
        } else {
          // element does not exist:
          low = mid + 1;
        }
      } else { // if right part is sorted:
        if (nums[mid] <= target && target <= nums[high]) {
          // element exists:
          low = mid + 1;
        } else {
          // element does not exist:
          high = mid - 1;
        }
      }
    }
    return -1;
  }
};