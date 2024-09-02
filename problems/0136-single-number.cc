// like every other problem only thing that came to my mind was hashmap

class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    unordered_map<int, int> freq;
    for (int n : nums) {
      freq[n]++;
    }

    vector<int> res;
    for (auto &pair : freq) {
      if (pair.second == 1) {
        res.push_back(pair.first);
      }
    }

    return res;
  }
};

//we couldve have used xor too
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int num = nums[0];
      for(int i=1; i<nums.size(); i++)
        num = num^nums[i];
        return num;
    }
};