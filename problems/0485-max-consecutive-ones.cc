class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxc = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1){
                cnt++;
                maxc = max(cnt,maxc);
            } else {
            cnt = 0;
            }
        }
        return maxc;
    }
};
