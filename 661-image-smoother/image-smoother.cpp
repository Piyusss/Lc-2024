class Solution {
public:
    vector<vector<int>>directions={
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,0},{0,1},
        {1,-1},{1,0},{1,1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();

        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sumOfNeigh=0;
                int cntOfNeigh=0;

                for(auto &it:directions){
                    int d_i=i+it[0];
                    int d_j=j+it[1];

                    if(d_i>=0 && d_j>=0 && d_i<=n-1 && d_j<=m-1){
                        sumOfNeigh+=img[d_i][d_j];
                        cntOfNeigh++;
                    }
                }
                ans[i][j]=sumOfNeigh/cntOfNeigh;
            }
        }
        return ans;
    }
};