class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<int> drow(n,0) ,dcol(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0) {
                    drow[i] = 1;
                    dcol[j] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(drow[i] == 1 || dcol[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};