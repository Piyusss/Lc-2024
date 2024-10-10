class Solution {
public:

int dp[101][101][201];
string s1,s2,s3;
int n,m,SS;

bool f(int i,int j,int k){
    if(i==n && j==m && k==SS) return 1;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    bool res1=0,res2=0;
    if(s1[i]==s3[k])res1=f(i+1,j,k+1);
    if(s2[j]==s3[k])res2=f(i,j+1,k+1);

    return dp[i][j][k] = res1 || res2;
}
    bool isInterleave(string S1, string S2, string S3){
        n=S1.size();
        m=S2.size();
        SS=S3.size();

        if(n+m != SS) return 0;

        s1=S1;s2=S2;s3=S3;

        memset(dp,-1,sizeof(dp));

        return f(0,0,0);
    }
};