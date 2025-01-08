class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size() - 1; i++){
            for(int j = i + 1; j < words.size(); j++) {
                if(isprefix(words[i],words[j]) && issuffix(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }

private:
    int isprefix(const string &s1, const string &s2){
        int m = s1.size();
        int n = s2.size();

        if(m > n) return false;
        for(int i = 0; s1[i] != '\0'; i++ ){
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }

    int issuffix(const string &s1, const string &s2){
        int m = s1.size();
        int n = s2.size();

        if(m > n) return false;
        for(int i = m-1; i >= 0; i-- ){
            if(s1[i] != s2[n-(m-i)]) return false;
        }
        return true;
    }


};
// so this was a kinda simple problem, the time complexity is very poor tho,
