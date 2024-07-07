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

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int maxnow = INT_MIN;
    int maxend = 0;
    for (int i = 0; i < nums.size(); i++) {
      maxend += nums[i];
      if (maxnow < maxend) {
        maxnow = maxend;
      }
      if (maxend < 0) {
        maxend = 0;
      }
    }
    return maxnow;
  }
};

// i somehow did it, but this was the hardest problem ive encountered till now.