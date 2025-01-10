// well we couldve use some other approach,consider one hashmap, where we contain, the count 
// and in another hashmap we contain the require words, and then just check if they match, and pushback that into the ans
class Solution {
public:
    vector<string> wordSubsets(vector<string>& mainWords, vector<string>& requiredWords) {
        unordered_map<char, int> maxFreqRequired;
        
        for (const string& word : requiredWords) {
            unordered_map<char, int> currFreq;
            for (char c : word) {
                currFreq[c]++;
            }
            for (const auto& [ch, freq] : currFreq) {
                maxFreqRequired[ch] = max(maxFreqRequired[ch], freq);
            }
        }
        
        vector<string> result;
        for (const string& word : mainWords) {
            unordered_map<char, int> currFreq;
            for (char c : word) {
                currFreq[c]++;
            }
            
            bool isUniversal = true;
            for (const auto& [ch, freq] : maxFreqRequired) {
                if (currFreq[ch] < freq) {
                    isUniversal = false;
                    break;
                }
            }
            
            if (isUniversal) {
                result.push_back(word);
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<string> wordSubsets(vector<string>& mainWords, vector<string>& requiredWords) {
        int maxCharFreq[26] = {0};
        int tempCharFreq[26];
        
        for (const auto& word : requiredWords) {
            memset(tempCharFreq, 0, sizeof tempCharFreq);
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxCharFreq[i] = max(maxCharFreq[i], tempCharFreq[i]);
            }
        }
        // i honestly dont know this question
        vector<string> universalWords;
        for (const auto& word : mainWords) {
            memset(tempCharFreq, 0, sizeof tempCharFreq);
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (maxCharFreq[i] > tempCharFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                universalWords.emplace_back(word);
            }
        }
        return universalWords;
    }
};



