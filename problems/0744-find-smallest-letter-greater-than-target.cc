class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans = -1;
        int low = 0; 
        int high = letters.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(letters[mid] > target) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans>-1? letters[ans]: letters[0];
    }
};

// this was my inital approach
//
// but as usual i wrote shitty code, how do i improve it hmmm? 
// look above ^^^^^^/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans = -1;
        int low = 0; 
        int high = letters.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(letters[mid] > target) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans>-1? letters[ans]: letters[0];
    }
};
