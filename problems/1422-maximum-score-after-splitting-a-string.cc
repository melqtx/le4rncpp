class Solution {
public:
    int maxScore(string s) {
        int maxScore = 0;
        int n = s.length();
        
        for(int i = 1; i < n; i++) {
            int leftZeros = 0;
            int rightOnes = 0;
            
            // Count zeros in left part
            for(int j = 0; j < i; j++) {
                if(s[j] == '0') leftZeros++;
            }
            
            // Count ones in right part
            for(int j = i; j < n; j++) {
                if(s[j] == '1') rightOnes++;
            }
            
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        return maxScore;
    }
}; 
// well this couldve been much better tbh.
// found this while looking for a better approach
class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int maxScore = 0;
        
        for (int i = 1; i < n; i++) {
            int leftZeros = count(s.begin(), s.begin() + i, '0');
            int rightOnes = count(s.begin() + i, s.end(), '1');
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        
        return maxScore;
    }
};
