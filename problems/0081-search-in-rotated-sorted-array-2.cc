class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return true;

            //check for dups
            //this is one of the edge case
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            //do the same thing we did in roatated array 1; since we eliminated dups;
            //check if the left half is sorted
            if(nums[low] <= nums[mid]) {
                if(nums[low] <= target && nums[mid] >= target) {
                    high = mid - 1;
                }else {
                    low = mid + 1;
                }
            }else {
                if(nums[mid] <= target && nums[high] >= target){
                    low = mid + 1;
                }else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
