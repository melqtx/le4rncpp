class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long right = 0;
        long long left = 0;
        int res = 0;

        for(int num: nums){
            right+=num;
        }

        for(int i = 0; i < nums.size() -1; i++){
            left = left + nums[i];
            right = right - nums[i];

            if(left >= right) res++;
        }
        return res;
    }
};

// kind of on the easier side,
// mistakes i was doing:
// took int instead of long long, used the accumulate function, with 0 not 0ll this is used to accumulate long long
// cya on the next one
