class Solution {
public:
    int dp[1000+1][1000+1];

    int longestCommonSubsequence(string s, string t){
        int n=s.size();
        int m=t.size();
        memset(dp,0,sizeof(dp));
        
        for(int j=1;j<=m;j++)dp[0][j-1]=0;
        for(int i=1;i<=n;i++)dp[i-1][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];
    }

};