#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends
class Solution {
public:
    int lenOfLongestSubbarr(vector<int>& arr, int k) {
        map<int, int> presum;
        int sum = 0;
        int maxlen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == k)
                maxlen = max(maxlen, i + 1);
            if (presum.find(sum - k) != presum.end()) {
                int len = i - presum[sum - k];
                maxlen = max(maxlen, len);
            }
            if (presum.find(sum) == presum.end())
                presum[sum] = i;
        }

        return maxlen;
    }
};

// Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value)
            arr.push_back(value);

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubbarr(arr, k) << "\n";
        cout << "\n";
    }

    return 0;
}

// not the main question, but a prerequisite for this one,:
