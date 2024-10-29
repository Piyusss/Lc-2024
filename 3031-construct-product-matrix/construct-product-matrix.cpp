class Solution {
public:

int M=12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int start=1;
        vector<vector<int>>left(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                left[i][j]= start;
                start= ((start%M)*(grid[i][j]%M)) % M;
            }
        }

        int end=1;
        vector<vector<int>>right(n,vector<int>(m,1));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                right[i][j]=end;
                end= ((end%M)*(grid[i][j]%M)) % M;
            }
        }

        vector<vector<int>>res(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]= ((left[i][j])*(right[i][j])) % M;
            }
        }

        return res;

    }
};