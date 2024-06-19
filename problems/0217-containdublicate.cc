/*
1. Initialize an empty hash set.
2. Iterate through each element num in the input array nums:
    - If num is already present in the hash, return true as we have found a duplicate.
    - Otherwise, add num to the hash.
3. else return false.
---------
this code runs in big oh of N.

*/
class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> hash;

        for (int num : nums) {
            if (hash.count(num) > 0) {
                return true; 
            }

            hash.insert(num);
        }

        return false; 
    }
};

/*
second approach could've been using a pointer, sort the array
check weather the element mathces, if ye then true, else false;
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
        
    }
};
