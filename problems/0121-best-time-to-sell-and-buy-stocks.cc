class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int left = 0;  // Buy
    int right = 1; // Sell
    int max_profit = 0;
    while (right < prices.size()) {
      int currentProfit = prices[right] - prices[left]; // our current Profit
      if (prices[left] < prices[right]) {
        max_profit = max(currentProfit, max_profit);
      } else {
        left = right;
      }
      right++;
    }
    return max_profit;
  }
};

class Solution {
  :wq
public:

    int maxProfit(vector<int>& prices) {
        int min = 0;
        int profit = 0;
        for(int i = 0; i <prices.size();i++){
            if(prices[i]<prices[min])
                min = i;
            profit = max(profit,prices[i]-prices[min]);
        }
        return profit;
    }
};


// we could have solved this using kadanes algorithm as well.
//
// maximum subarray problem

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int min = INT_MAX;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            }
            else if (prices[i] > min) {
                maxi = max(prices[i] - min, maxi);
            }
        }
        
        return maxi;
    }
};
