
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


// i lowkey dont give a flying fuck
// can we not use a simple condition? why complicate?

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        
        if(nums[nums.size()-1] > nums[nums.size()-2]) 
            return nums.size()-1;
        
        for(int i = 1; i < nums.size()-1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                return i;
            }
        }
        
        return 0;
    }
};

//nvm this is slow as fuck
