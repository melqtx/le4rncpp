class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // the stoi function converts the str into int 
        vector<int> minutes(timePoints.size());
        for (int i = 0; i < timePoints.size(); i++) {
            string time = timePoints[i];
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3));
            minutes[i] = h * 60 + m;
        }

        //sorting the aray in asc
        sort(minutes.begin(), minutes.end());

        int ans = INT_MAX;
        for(int i = 0; i < minutes.size() - 1; i++) {
            ans = min(ans, minutes[i+1] - minutes[i]);
        }
        return min(ans, 24 * 60 - minutes[minutes.size() - 1] + minutes[0]);

    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

/*
        return min(ans, 24 * 60 - minutes[minutes.size() - 1] + minutes[0]);
this function right here is the main edge case.

*/
