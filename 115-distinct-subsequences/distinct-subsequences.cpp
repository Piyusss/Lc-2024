class Solution {
public:

double dp[1001][1001];

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        memset(dp,0,sizeof(dp));

		for(int i=0;i<=n;i++)dp[i][0]=1;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i-1]==t[j-1]){
				    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
				}
				else dp[i][j]=dp[i-1][j];
		}
	}
	return (int)dp[n][m];
    }
};