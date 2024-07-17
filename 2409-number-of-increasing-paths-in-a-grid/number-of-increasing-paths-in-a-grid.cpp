class Solution {
public:
int maxi=1;
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
int M=1E9+7;
int dp[1001][1001];

int dfs(int i,int j,vector<vector<int>>& matrix){

    if(dp[i][j]!=-1)return dp[i][j];

    int cnt=1;
    for(auto &it:dir){
        int ni=i+it[0];
        int nj=j+it[1];

        if(ni>=0 && ni<n && nj>=0 && nj<m && matrix[ni][nj]>matrix[i][j]){
            cnt=(cnt+dfs(ni,nj,matrix))%M;
        }
    }

    return dp[i][j]=cnt;
}
    int countPaths(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();

        memset(dp,-1,sizeof(dp));

        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(i,j,matrix);
                sum=(sum+dp[i][j])%M;
            }
        }

        return sum%M;
    }
};