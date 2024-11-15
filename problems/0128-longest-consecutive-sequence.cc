class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longest = 1;
        int cnt = 0;
        int lastsm = INT_MAX;
        if (nums.size() == 0) return 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] - 1 == lastsm){
                cnt++;
                lastsm = nums[i];
            }else if(nums[i] != lastsm){
                cnt = 1;
                lastsm = nums[i];
            }
            longest = max(cnt, longest);
        }
        return longest;
    }
};// not the best one, but easily understandable.

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    int n = nums.size();

    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
      st.insert(nums[i]);
    }

    for (auto it : st) {
      if (st.find(it - 1) == st.end()) {
        int cnt = 1;
        int x = it;
        while (st.find(x + 1) != st.end()) {
          x++;
          cnt++;
        }
        longest = max(longest, cnt);
      }
    }
    return longest;
  }
};

/*
    Given unsorted array, return length of longest consecutive sequence
    Ex. nums = [100,4,200,1,3,2] -> 4, longest is [1,2,3,4]

    Store in hash set, only check for longer seq if it's the beginning

    Time: O(n)
    Space: O(n)
*/
