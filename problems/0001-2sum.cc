class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // Create an unordered map to store the complement of each element and its
    // index
    unordered_map<int, int> numMap;

    // Create a vector to store the result (indices of the two numbers)
    vector<int> result;

    // Iterate through the nums array
    for (int i = 0; i < nums.size(); i++) {
      // Calculate the complement of the current element
      int complement = target - nums[i];

      // Check if the complement exists in the numMap
      if (numMap.find(complement) != numMap.end()) {
        // If the complement exists, it means we have found the two indices
        // that sum up to the target

        // Add the index of the complement to the result vector
        result.push_back(numMap[complement]);

        // Add the index of the current element to the result vector
        result.push_back(i);

        // Return the result vector
        return result;
      }

      // If the complement doesn't exist in the numMap,
      // add the current element and its index to the numMap
      numMap[nums[i]] = i;
    }

    // If no pair is found that sums up to the target,
    // return an empty result vector
    return result;
  }
};