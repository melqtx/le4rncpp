//first approach is this.
class Solution {
public:
  //always write a function yourself  
  int findMax(const vector<int>& piles) {
        int maxBananas = INT_MIN;
        for (int pile : piles) {
            maxBananas = max(maxBananas, pile);
        }
        return maxBananas;
    }

    long long int calculateTotalHours(const vector<int>& piles, int hourly) {
        long long int totalHours = 0;
        for (int pile : piles) {
            totalHours += ceil(static_cast<double>(pile) / hourly);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int low = 1;
        int high = findMax(piles);
        
        while (low <= high) {
            int mid = (low + high) / 2;
            long long int totalHours = calculateTotalHours(piles, mid);
            
            if (totalHours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
// this is the best possible case, here were directly using the max function and using it.
class Solution {
public:
    long long hourly(vector<int>& piles, int k) {
        long long ht = 0;
        for(int pile : piles){
            ht += (pile + k - 1) / k;
        }
        return ht;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(begin(piles), end(piles));

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalh = hourly(piles, mid);
            if(totalh <= h){ // increase the speed
                high = mid-1;
            }else{ // decrease the speed
                low = mid + 1;
            }
        }
        return low;
    }
};// here we use long long as we get a signed integer overflow otherwise
// we use l <= r as we are doing an exact value search
// we want to include the case where l == r, and we know that this terminates, as both cases ignore the curr_k for the next iteration
// we know we need an (n)logk alg as k can be between 10^9 and we want to find the optimal k in that range
// for each k, we test to check the h value associated
//


class Solution {
public:
    long long int hourlyrate(const vector<int>&piles, int hourly ){
        long long int totalht = 0;
        for(int pile: piles){ 
            totalht += ceil(static_cast<double>(pile)/hourly);
            }
        return totalht;
    }
       
    int minEatingSpeed(vector<int>& piles, int h) {
         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int low = 1;
        int high = *max_element(begin(piles), end(piles));
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long int totalh = hourlyrate(piles, mid);
            if(totalh <= h) {
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};

