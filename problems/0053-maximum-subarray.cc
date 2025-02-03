class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max_sum = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      int sum = 0;
      for (int j = i; j < nums.size(); j++) {
        sum += nums[j];
        max_sum = max(max_sum, sum);
      }
    }
    return max_sum;
  }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {  // Fixed j < nums.size()
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};

// this doesnt even pass all the testcases, but if it works it works.
/*
    max_so_far = INT_MIN
    max_ending_here = 0

Loop for each element of the array

  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far
*/
// kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+= nums[i];
            if(sum > maxi) {
                maxi = sum;
            }
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};
