class Solution {
public:

int dp[502][502];

    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        memset(dp,0,sizeof(dp));

        for(int j=0;j<=m;j++)dp[0][j]=j;
        for(int i=1;i<=n;i++)dp[i][0]=i;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){   
            if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])); //DELETE , INSERT , REPLACE
            }
        }

        return dp[n][m];
    }
};