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


end() returns an iterator pointing to the position just after the last element in the container
It doesn't point to any actual element (it's a "past-the-end" iterator)
It's commonly used as a sentinel value to indicate "not found" or the end of iteration
When comparing with find(), the expression find(value) == end() means "the value was not found in the set"
/*
    Given unsorted array, return length of longest consecutive sequence
    Ex. nums = [100,4,200,1,3,2] -> 4, longest is [1,

end() returns an iterator pointing to the position just after the last element in the container
It doesn't point to any actual element (it's a "past-the-end" iterator)
It's commonly used as a sentinel value to indicate "not found" or the end of iteration
When comparing with find(), the expression find(value) == end() means "the value was not found in the set"2,3,4]

    Store in hash set, only check for longer seq if it's the beginning

    Time: O(n)
    Space: O(n)
*/

// i read cses last week, so made the code more efficient for cp 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        unordered_set<int> st(nums.begin(), nums.end());
        if(nums.size() == 0) return 0;
        int longest = 1;
        for(auto it: st) {
            if(st.find(it - 1) == st.end()){
                int cnt = 1; 
                while(st.find(it + cnt) != st.end()) {
                    cnt = cnt + 1;
                }
                longest = max(cnt,longest);
            }
        }
        return longest;
    }
};
