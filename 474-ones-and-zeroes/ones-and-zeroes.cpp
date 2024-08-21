class Solution {
public:

int dp[601][101][101];
int si;

int f(int idx,vector<string>& strs,int n,int m,int one,int zero){
    if(idx==si)return 0;

    if(dp[idx][one][zero]!=-1)return dp[idx][one][zero];

    int curOne=0,curZero=0;
    string s=strs[idx];
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')curZero++;
        else curOne++;
    }

    int pick=0;
    if(one+curOne<=n && zero+curZero<=m) pick=1+f(idx+1,strs,n,m,one+curOne,zero+curZero);
    int not_pick=f(idx+1,strs,n,m,one,zero);

    return dp[idx][one][zero] = max(pick,not_pick);
    
}
    int findMaxForm(vector<string>& strs, int m, int n){
        si=strs.size();
        memset(dp,-1,sizeof(dp));
        return f(0,strs,n,m,0,0);
    }
};