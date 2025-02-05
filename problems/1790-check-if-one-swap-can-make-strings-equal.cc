class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff_pos;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i])
                diff_pos.emplace_back(i);
        }
        if(diff_pos.empty())
            return true;
        // only one pair of diff positions, check if swapping makes them equal
        if(diff_pos.size() == 2) {
            int low = diff_pos[0];
            int high = diff_pos[1];
            //Cross comparison
            if (s1[low] == s2[high] && s2[low] == s1[high]) {
                return true;
            }
        }
        
        return false;
    }
};
