class Solution {
public:

int dp[501][501];

int f(int i,int j,string &s,string &t){
    if(i<0)return j+1; // INSERT IN S
    if(j<0)return i+1; // DELETE IN S

    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i]==t[j])return dp[i][j]=f(i-1,j-1,s,t);
    return dp[i][j]=1+min(f(i-1,j,s,t),min(f(i,j-1,s,t),f(i-1,j-1,s,t))); //DELETE , INSERT , REPLACE

}
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        memset(dp,-1,sizeof(dp));

        return f(n-1,m-1,s,t);
    }
};