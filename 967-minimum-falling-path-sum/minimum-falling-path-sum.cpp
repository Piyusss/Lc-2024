class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            dp[0][i]=m[0][i];
        }

        for(int i=1;i<=n-1;i++){
            for(int j=0;j<=n-1;j++){
                int up=m[i][j];
                if(i>0)up+=dp[i-1][j];else up+=1e9;

                int dl=m[i][j];
                if(i>0 && j>0)dl+=dp[i-1][j-1];else dl+=1e9;
                
                int dr=m[i][j];
                if(j+1<n)dr+=dp[i-1][j+1];else dr+=1e9;
                
                dp[i][j]=min(up,min(dr,dl));
            }
        }
        int mini=1e9;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
};