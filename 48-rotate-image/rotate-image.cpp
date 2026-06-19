class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>new_matrix(n,vector<int>(m,0));

        int cnt=0;
        for(int i=0;i<n;i++){
            cnt=0;
            for(int j=0;j<m;j++){
                int cur_el=matrix[i][j];

                new_matrix[cnt][n-1-i]=cur_el;
                cnt++;
            }
        }

        matrix=new_matrix;
        return;
    }
};