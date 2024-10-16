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

// THIS JUST WORKS. AND IDK HOW CAN I MAKE IT BETTER THAN THIS.
//
//
//
class Solution {
public:
    int calculateSum(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(begin(nums), end(nums));
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int sum = calculateSum(nums, mid);
            
            if (sum <= threshold) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
