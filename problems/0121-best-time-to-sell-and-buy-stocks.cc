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