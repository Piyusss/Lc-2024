class Solution {
public:

int dp[21][21];

bool f(int i,int j,string &s,string &p){
    if(j==p.length()){
        if(i==s.length())return 1;
        return 0;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    bool first_char_match=0;
    if(i<s.length() && (p[j]==s[i] || p[j]=='.'))first_char_match=1;

    if(p[j+1]=='*'){
        bool not_take=f(i,j+2,s,p);
        bool take=first_char_match && f(i+1,j,s,p);
        return dp[i][j]= not_take|| take;
    }

    return dp[i][j]= first_char_match && f(i+1,j+1,s,p);
}
    bool isMatch(string s, string p){
        memset(dp,-1,sizeof(dp));
        return f(0,0,s,p);
    }
};