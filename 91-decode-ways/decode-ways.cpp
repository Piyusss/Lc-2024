class Solution {
public:

int dp[101];

int f(string &s,int &n,int idx){
    if(idx==n)return 1;
    if(idx>n ||  s[idx]=='0')return 0;

    if(dp[idx]!=-1)return dp[idx];

    int res=f(s,n,idx+1);
    if( (idx+1<=n-1 && s[idx]=='1') || ( idx+1<=n-1 && s[idx]=='2' && s[idx+1]<='6' ))res+=f(s,n,idx+2);

    return dp[idx]= res;
}
    int numDecodings(string s){
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return f(s,n,0);
        
    }
};