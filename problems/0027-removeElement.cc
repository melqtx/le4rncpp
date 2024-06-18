//y is iterating through the array, while x con

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int x = 0;
        int n = nums.size();
        for(int y=0; y<n; y++){
            if(nums[y]!=val)
                swap(nums[x++], nums[y]);
        }

        return x;
    }
};


//we could've used a two pointer approach as well.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int x = nums.size()-1;
        int count = 0;
        int i = 0;

        while(i <= x){
            if(nums[i] == val){
                count++;
                swap(nums[i], nums[x--]);
            }
            else{
                i++;
            }
        }

        return (nums.size()-count);
    }
};
