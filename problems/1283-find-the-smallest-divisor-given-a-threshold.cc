class Solution { public: int smallestDivisor(vector<int>& nums, int threshold) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low < high) {
            int sum = 0;

            int mid = low + (high - low) / 2;
            for(int i: nums) {
                sum+= (i + mid - 1) / mid;
            }
            if(sum <= threshold) {
                high = mid;
            }else {
                low = mid + 1;
            }
        }
        return low;
    }
};
// im repeating one mistake again and again, taking low as zero, will cause division by zero error
// do not mess up ther
// THIS JUST WORKS. AND IDK HOW CAN I MAKE IT BETTER THAN THIS.
class Solution {
public:
    int ans(vector<int>& nums, int divisor) {
        int a=0;
        for(int num: nums){
            a+= (num + divisor - 1) / divisor;

        }
        return a;
    }
           

    int smallestDivisor(vector<int>& nums, int threshold) {
         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            int sum = ans(nums,mid);
            if(sum <= threshold){
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};

//added another function, but the time complexity remains same;
