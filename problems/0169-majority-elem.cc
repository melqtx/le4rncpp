class Solution {
public:
  int majorityElement(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      int cnt = 0;
      for (int j = 0; j < nums.size(); j++) {
        if (nums[i] == nums[j])
          cnt++;
      }
      if (cnt > nums.size() / 2)
        return nums[i];
    }
    return -1;
  }
};

/*
this runs slower than your grandma, i need to make it faster, thinks....
 well it is rightly said, if you dont know what to do, use a map, hash map
motherfucker.
*/

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
      hash[nums[i]]++;
    }
    for (auto it : hash) {
      if (it.second > (nums.size() / 2)) {
        return it.first;
      }
    }
    return -1;
  }
};

// wake up babe, we got moore's voting algorithm,
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int cnt = 0;
    int v;
    for (int i = 0; i < nums.size(); i++) {
      if (cnt == 0) {
        cnt = 1;
        v = nums[i];
      } else if (nums[i] == v) {
        cnt++;
      } else {
        cnt--;
      }
    }
    int cunt;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == v)
        cunt++;
    }
    if (cunt > (nums.size() / 2)) {
      return v;
    }
    return -1;
  }
};