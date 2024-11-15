class Solution {
private:
    static const long int MARKER = INT_MAX;
    void rowtozero(vector<vector<int>>& matrix, int i, int m) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] != 0) {
                matrix[i][j] = MARKER;
            }
        }
    }
    void coltozero(vector<vector<int>>& matrix, int j, int n) {
        for(int i = 0; i < n; i++) {
            if(matrix[i][j] != 0) {
                matrix[i][j] = MARKER;
            }
        }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    rowtozero(matrix, i, m);
                    coltozero(matrix, j, n);
                }
            }
        }
        
        // Convert all -1s to 0s
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == MARKER) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
