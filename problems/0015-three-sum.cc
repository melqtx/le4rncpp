// just had threeSum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int l = i + 1;
            int r = n - 1;
            
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if(sum < 0) l++;
                else r--;
            }
        }
        return result;
    }
};

// another Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        vector<vector<int>> a;
        sort(n.begin(),n.end());
        for(int i=n.size()-1;i>1;i--){
            int l=0,r=i-1;
            while(l<r){
                int s=n[l]+n[r]+n[i];
                if(s>0)r--;
                else if(s<0)l++;
                else{
                    a.push_back({n[l],n[r],n[i]});
                    while(l<r&&n[l]==n[l+1])l++;
                    while(l<r&&n[r]==n[r-1])r--;
                    l++;r--;
                }
            }
            while(i>1&&n[i]==n[i-1])i--;
        }
        return a;
    }
};
