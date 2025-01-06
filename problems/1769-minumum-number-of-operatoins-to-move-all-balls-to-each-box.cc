class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.length());
        for(int i = 0; i < boxes.length(); i++){
            if(boxes[i]== '1'){
                for(int j = 0; j < boxes.length(); j++){
                    answer[j] = answer[j] + abs(j -i);
                }
            }
        }
        return answer;
    }
};

// shitties question ever
