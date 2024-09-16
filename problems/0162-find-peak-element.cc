
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0,high = nums.size() - 1;
        if(nums.size() == 1) return 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(mid > 0 && nums[mid] < nums[mid-1]) {
                high = mid - 1;
            }else if(mid < nums.size() -1 && nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }else { 
                return mid;
            }
        }
        return -1;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

//weird ass question tbh.
