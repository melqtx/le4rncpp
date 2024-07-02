class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> countMap;
    vector<int> result;

    // Count occurrences of elements in nums1
    for (int num : nums1) {
      countMap[num]++;
    }

    // Check elements in nums2 and build the result
    for (int num : nums2) {
      if (countMap[num] > 0) {
        result.push_back(num);
        countMap[num]--;
      }
    }

    return result;
  }
};

this one was extremely easy, but me being me with two braincells took an hour.
