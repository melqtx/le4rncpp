//just do a simple binary search, instead of returning -1, return low.
//its a lower bound ass hole.:wq

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (target == nums[m]) {
                return m;
            } else if (target < nums[m]) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
