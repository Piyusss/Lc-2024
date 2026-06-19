class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j || i>j) continue;
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        if(!(m&1)) m-=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<=m/2;j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }

        return;
    }
};