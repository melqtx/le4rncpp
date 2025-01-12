class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length() % 2 != 0) return false;
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(locked[i] == '1' && s[i] == ')') {
                if(st.empty()) return false;
                st.pop();
            } else {
                st.push(i);
            }
        }
        while(!st.empty()) st.pop();
        
        for(int i = s.length()-1; i >= 0; i--) {
            if(locked[i] == '1' && s[i] == '(') {
                if(st.empty()) return false;
                st.pop();
            } else {
                st.push(i);
            }
        }
        return true;
    }
};

//thx neetcode
