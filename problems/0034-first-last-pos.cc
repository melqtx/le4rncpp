/*
look the most simplified approach could have been was using upper and lower
bound, the answer we need to return is just {lower bound, upperbound -1}, so
there will be one edge case edge case= if lb == x and arr[lb] != x; where we
will be returning {-1,-1}.
*/

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> ans = {-1, -1};
    if (nums.empty()) {
      return ans;
    }
    int n = nums.size(), l = 0, h = n - 1;
    while (l < h) {
      int m = l + (h - l) / 2;
      if (nums[m] < target) {
        l = m + 1;
      } else {
        h = m;
      }
    }
    if (nums[l] != target) {
      return ans;
    }
    ans[0] = l;
    h = n - 1;
    while (l < h) {
      int m = l + (h - l + 1) / 2;
      if (nums[m] > target) {
        h = m - 1;
      } else {
        l = m;
      }
    }
    ans[1] = l;
    return ans;
  }
};
//here but it wouldve consudmed more memory.
// here comes the bruteforce bitch
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last=-1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return {first,last};
    }
};

//fuck my life, i literally forgor, the way i used to do this question man

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        if(nums.empty()) return ans;
        
        // Find first position
        int l = 0, h = nums.size() - 1;
        while(l <= h) {
            int m = l + (h-l)/2;
            if(nums[m] == target) {
                ans[0] = m;       
                h = m - 1;
            }
            else if(nums[m] < target) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        
        if(ans[0] == -1) return ans;  // Target not found
        l = ans[0]; 
        h = nums.size() - 1;
        while(l <= h) {
            int m = l + (h-l)/2;
            if(nums[m] == target) {
                ans[1] = m;       
                l = m + 1;         
            }
            else if(nums[m] < target) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        
        return ans;
    }
};
