class Solution {
public:
  void sortColors(vector<int> &nums) {
    int cnt0 = 0;
    int cnt1 = 1;
    int cnt2 = 2;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0)
        cnt0++;
      else if (nums[i] == 1)
        cnt1++;
      else
        cnt2++;
    }

    for (int i = 0; i < cnt0; i++)
      nums[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++)
      nums[i] = 1;
    for (int i = cnt0 + cnt1; i < nums.size(); i++)
      nums[i] = 2;
  }
};

// this is the not the optimal approach, but this kind of works.

// imma find the best approach.
// its the dutch flag algorith bois.

pretty simple

    class Solution {
public:
  void sortColors(vector<int> &nums) {
    int l = 0, m = 0, h = static_cast<int>(nums.size()) - 1;
    while (m <= h) {
      if (nums[m] == 0) {
        std::swap(nums[l], nums[m]);
        ++l;
        ++m;
      } else if (nums[m] == 1) {
        ++m;
      } else {
        std::swap(nums[m], nums[h]);
        --h;
      }
    }
  }
};