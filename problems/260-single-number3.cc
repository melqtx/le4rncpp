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