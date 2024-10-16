
//tbh idk how does adding this runs my code faster
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        for(auto &pair: map){
            if(pair.second == 1){
                return pair.first;
            }
        }
        return -1;
    }
};


