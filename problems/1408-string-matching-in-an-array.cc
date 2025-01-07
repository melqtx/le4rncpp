class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words.size(); j++) {
                if(i == j) continue;
                if(words[j].find(words[i]) != -1) {  //til string::npos is a thing
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        set<string> s(ans.begin(), ans.end());  // Remove duplicates
        return vector<string>(s.begin(), s.end());
    }
};
