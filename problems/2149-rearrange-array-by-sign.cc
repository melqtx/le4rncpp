class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    int posi = 0, negi = 1;

    for (int i = 0; i < n; i++) {
      if (nums[i] < 0) {
        ans[negi] = nums[i];
        negi += 2;
      } else {
        ans[posi] = nums[i];
        posi += 2;
      }
    }
    return ans;
  }
};


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                neg.push_back(nums[i]);
            } else {
                pos.push_back(nums[i]);
            }
        }
        
        for(int i = 0; i < nums.size()/2; i++) {
            nums[2*i] = pos[i];
            nums[2*i + 1] = neg[i];
        }
        
        return nums;  
    }
};
