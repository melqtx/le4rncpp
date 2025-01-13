// if the frequency is odd, add one, else two

class Solution {
public:
    int minimumLength(string s) {
        vector<int> ls(26,0);
        int tlen = 0;
        // char frequency counting
        for(char cchar: s){
         ls[cchar - 'a']++;  
        }

        for(int it: ls) {
            if(it == 0) continue;
            if(it %2 == 0) {
                tlen = tlen + 2;
            } else {
                tlen = tlen + 1;
            }
        }
        return tlen;
    }
};
