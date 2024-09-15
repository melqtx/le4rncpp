class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            //checking for left half
            //it is logical, if the one half is sorted, 
            //so the index on the left will always contain the min.
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else { // we checked for right half here
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }

        }
        return ans;
    }
};
