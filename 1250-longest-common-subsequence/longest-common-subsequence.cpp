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

        // return dp[n][m];

    //PRINT LCS
    //     int len=dp[n][m];
    //     string st="";
    //     for(int i=0;i<len;i++)st+='$';

    //     int i=n,j=m,idx=len-1;
    //     while(i && j){
    //       if(s[i-1]==t[j-1]){
    //         st[idx]=s[i-1];
    //         i--;j--;
    //         idx--;
    //       }
    //       else{
    //         if(dp[i-1][j]>dp[i][j-1]){
    //           i--;
    //         }
    //         else{
    //           j--;
    //         }
    //       }
    //     }
    // //   return st;
    // cout<<st;
    //PRINT LCS

    return dp[n][m];
    }

};