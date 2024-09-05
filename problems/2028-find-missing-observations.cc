class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int totalRolls = rolls.size() + n;
        int totalSum = mean * totalRolls;
        int existingSum = 0;

        for (int roll : rolls) {
            existingSum += roll;
        }

        int missingSum = totalSum - existingSum;

        if (missingSum < n || missingSum > n * 6) {
            return {};
        }

        int baseValue = missingSum / n;
        int remainingSum = missingSum % n;

        vector<int> result(n, baseValue);

        for (int i = 0; i < remainingSum; i++) {
            result[i]++;
        }

        return result;
    }
};

//had to take neetcodes help to pull this off, but upon 
//understanding its a cake walk.
