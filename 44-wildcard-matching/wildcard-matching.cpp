class Solution {
public:

bool dp[2001][2001];

    bool isMatch(string p, string s){
        int n=s.size();
        int m=p.size();
        memset(dp,0,sizeof(dp));
        

        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            int flag=0;
            for(int check=1;check<=i;check++)if(s[check-1]!='*'){dp[i][0]=0;flag=1;}
            if(flag==0)dp[i][0]=1;
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || s[i-1]=='?')dp[i][j]= dp[i-1][j-1];
                else if(s[i-1]=='*')dp[i][j]= dp[i-1][j] || dp[i][j-1];
            }
        }

        return dp[n][m];
    }
};