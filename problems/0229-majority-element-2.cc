class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            //to not get dubs in the result
            if(find(result.begin(), result.end(), nums[i]) != result.end())
                continue;
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(nums[i] == nums[j])
                    count++;
            }
            if(count > n/3)
                result.push_back(nums[i]);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_set<int> result;  
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(result.count(nums[i]) > 0)
                continue;
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(nums[i] == nums[j])
                    count++;
            }
            
            if(count > n/3)
                result.insert(nums[i]);
        }
        return vector<int>(result.begin(), result.end());
    }
};

// son of a bitch, this is n^2 fuck
// a better Solution can be using a hashmap which we used in maj element 1
// other one was moores algorithm
