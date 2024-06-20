//leetcode gonna give me an award for wrting code slower than your grandma.
//i should find eh way to improve htis.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> hash;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            hash[nums[i]]++;

        }
        for (auto &pair: hash){
           if(pair.second!=1){
            return pair.first;
           }
            
        }
        
     return -1;    
    }

};

//well this might be faster, but i love slow(cries)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0]!=nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};
