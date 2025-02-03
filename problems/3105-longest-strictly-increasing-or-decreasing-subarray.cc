// simple apprach, where we take two variables, inc or dec
// aa im tired
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1;
        int mac = 1;
        int n = nums.size() - 1;
        for(int i = 0; i < n; i++){
            if(nums[i+1] > nums[i]) {
                inc++;
                dec = 1;
            }else if(nums[i+1] < nums[i]) {
                dec++;
                inc = 1;
            }else if(nums[i+1] == nums[i]) {
                inc = 1;
                dec = 1;
            }
            mac = max(mac, max(dec,inc));
        }
        return mac;
    }
};
