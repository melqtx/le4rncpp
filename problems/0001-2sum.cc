class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mpp;
        for(int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int more = target - a;
            if(mpp.find(more) != mpp.end()){
                return {mpp[more], i};
            }
            mpp[a] = i;
        }
        return {};
    }
};  


// this just works:wq
//
// using a hashm amp
