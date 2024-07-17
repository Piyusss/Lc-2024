class Solution {
public:

int maxi=1;
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
int dp[201][201];

int dfs(int i,int j,vector<vector<int>>& matrix){

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=0;
    for(auto &it:dir){
        int ni=i+it[0];
        int nj=j+it[1];

        if(ni>=0 && ni<n && nj>=0 && nj<m && matrix[ni][nj]>matrix[i][j]){
            ans=max(ans,1+dfs(ni,nj,matrix));
        }
    }
    return dp[i][j]=ans;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();

        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,1+dfs(i,j,matrix));
            }
        }

        return maxi;
    }
};