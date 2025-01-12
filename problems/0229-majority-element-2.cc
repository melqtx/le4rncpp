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

// gotta hail moores voting algorithm, well there were two things
// we did differently than the last 
// first we had to return an array basically vector
// and this time there could be two majority element,
// we take two counters this time,
// thing to keep in mind these two counters do not contains dub so we do it like that 
// at the end, just check if there exists a majority element


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int v1 = INT_MIN;
        int v2 = INT_MIN;
        int cnt2 = 0;


        for(int i = 0; i < nums.size(); i++){
            if(cnt1 == 0 && nums[i] != v2){
                cnt1=1;
                v1 = nums[i];
            }else if(cnt2 == 0 && nums[i] != v1) {
                cnt2 = 1;
                v2 = nums[i];
            }else if(nums[i] == v1) cnt1++;
            else if(nums[i] == v2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ls;
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(v1 == nums[i]) cnt1++;
            if(v2 == nums[i]) cnt2++;
        }
        int mini = (int)(nums.size()/3) +1;
        if(cnt1 >= mini) ls.push_back(v1);
        if(cnt2 >= mini) ls.push_back(v2);
        sort(ls.begin(), ls.end());
        return ls;
    }
};
