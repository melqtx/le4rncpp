

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

/*
    - Reverse the entire vector.
    - Reverse the parts you want to obtain the result.

    Time: O(1)
    Space: O(1)
*/
