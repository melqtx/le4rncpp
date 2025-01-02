/*
 words = ["aba", "bcb", "ece", "aa", "e"]
prefixsum = [1, 1, 2, 3, 4]  // cumulative count of valid words
queries = [[0,2], [1,4]]  // example queries

for query [0,2]:
- want count from index 0 to 2
- prefixsum[2] - prefixsum[-1] = 2 - 0 = 2 valid words

for query [1,4]:
- want count from index 1 to 4
- prefixsum[4] - prefixsum[0] = 4 - 1 = 3 valid words
 */ 

class solution {
public:
    bool isvowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    bool isvowelstring(string& word) {
        return isvowel(word[0]) && isvowel(word[word.length() - 1]);
    }
    
    vector<int> vowelstrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> answer;
        
        for(vector<int>& query : queries) {
            int start = query[0];  
            int end = query[1];    
            int count = 0;  
            for(int i = start; i <= end; i++) {
                if(isvowelstring(words[i])) {
                    count++;
                }
            }
            answer.push_back(count);
        }
        return answer;
    }
};

// would you believe me this fails just one test case, aaaaaaaaaaaaa fuck me
// neetcode to the rescue

class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixCount(words.size() + 1, 0);
        for(int i = 0; i < words.size(); i++) {
            prefixCount[i + 1] = prefixCount[i];
            if(isVowel(words[i][0]) && isVowel(words[i].back())) {
                prefixCount[i + 1]++;
            }
        }
        vector<int> answer;
        for(const vector<int>& query : queries) {
            int start = query[0];
            int end = query[1];
            int countInRange = prefixCount[end + 1] - prefixCount[start];
            answer.push_back(countInRange);
        }
        return answer;
    }
};

//this shit works, we couldve used a set of vowels as well, i wanna keep things simple
