class Solution {
public:

int dp[2001][2001];

bool f(int i,int j,string &s,string &p){
    if(i<0 && j<0)return 1;
    if(i<0 && j>=0)return 0;
    if(j<0 && i>=0){
        for(int check=0;check<=i;check++)if(s[check]!='*')return 0;
        return 1;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i]==p[j] || s[i]=='?')return dp[i][j]= f(i-1,j-1,s,p);
    if(s[i]=='*')return dp[i][j]= f(i-1,j,s,p) || f(i,j-1,s,p);

    return dp[i][j]= 0;
}
    bool isMatch(string p, string s){
        int n=s.size();
        int m=p.size();
        memset(dp,-1,sizeof(dp));
        return f(n-1,m-1,s,p);
    }
};