class Solution {
public:

int dp[1001][1001];

int f(int i,int j,string &s,string &t){
    if(i==s.size() && j==t.size())return 0;
    if(i==s.size())return static_cast<int>(t[j]) + f(i,j+1,s,t);
    if(j==t.size())return static_cast<int>(s[i]) + f(i+1,j,s,t);

    if(dp[i][j]!=-1)return dp[i][j];

    int mini=INT_MAX;
    if(s[i]!=t[j]){
        int delfirst=static_cast<int>(s[i]) + f(i+1,j,s,t);
        int delsecond=static_cast<int>(t[j]) + f(i,j+1,s,t);
        mini=min(mini,min(delfirst,delsecond));
    }
    else return dp[i][j]=f(i+1,j+1,s,t);

    return dp[i][j]=mini;
}
    int minimumDeleteSum(string s, string t){
        memset(dp,-1,sizeof(dp));
        return f(0,0,s,t);
    }
};