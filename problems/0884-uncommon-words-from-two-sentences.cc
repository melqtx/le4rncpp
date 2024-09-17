#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void countWords(const string& sentence, unordered_map<string, int>& wordCount) {
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            wordCount[word]++;
        }
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        countWords(s1, wordCount);
        countWords(s2, wordCount);
        
        vector<string> result;
        for (const auto& entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};

//this is considerd as an easy problem but fucked my brains out.
