class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> res;  // store the palindrome as string
        unordered_set<char> left;
        unordered_map<char, int> right;
        
        for(char c : s) {
            right[c]++;
        }
        for(char m : s) {
            right[m]--;  // Decrease count of current char
            for(char c : left) {
                if(right[c] > 0) {  // If char still exists on right
                    string palindrome = string(1, c) + m; // we dont actually needs the last char
                    res.insert(palindrome);
                }
            }
            left.insert(m);  
        }
        return res.size();
    }
};

/*
string palindrome = string(1, c) + m; // we dont actually needs the last char
instead of using this function, we couldve used,
string pal;
pal = pal + c;
pal = pal + m;
and then insert pal into result
*/
