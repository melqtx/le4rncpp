class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
   vector<int>orgnum=nums;
   sort(nums.begin(),nums.end());
   int left=0;
   int right=nums.size()-1;
   while(left<right)
   {
    int sum=nums[left]+nums[right];
    if(sum==target){
    break;
    }
    else if (sum<target){
        left++;
    }
    else{
        right--;
    }
   }
   vector<int>res;
   for(int i=0;i<orgnum.size();i++)
   {
    if(orgnum[i]==nums[left]||orgnum[i]==nums[right])
    {
        res.push_back(i);
        if(res.size()==2)
        {
            break;
        }
    }
   }
   return res;
    }

};
