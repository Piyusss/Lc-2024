class Solution {
public:

int dp[601][101][101];
int si,n,m;

int f(int idx,vector<string>& strs,int one,int zero){
    if(idx==si)return 0;

    if(dp[idx][one][zero]!=-1)return dp[idx][one][zero];

    return dp[idx][one][zero] = max((one+strs[idx].size()-count(strs[idx].begin(),strs[idx].end(),'0')<=n && zero+count(strs[idx].begin(),strs[idx].end(),'0')<=m ? 1+f(idx+1,strs,one+strs[idx].size()-count(strs[idx].begin(),strs[idx].end(),'0'),zero+count(strs[idx].begin(),strs[idx].end(),'0')) : 0),f(idx+1,strs,one,zero));
    
}
    int findMaxForm(vector<string>& strs, int M, int N){
        n=N;m=M;si=strs.size();
        memset(dp,-1,sizeof(dp));
        return f(0,strs,0,0);
    }
};