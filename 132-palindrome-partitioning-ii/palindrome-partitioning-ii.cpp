class Solution {
public:

int dp[2002];

bool isPal(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j])return 0;
        i++;
        j--;
    }
    return 1;
}

int f(int i , int n , string &s){
    if(i==n)return 0;

    if(dp[i]!=-1)return dp[i];

    int mini=1e9;
    for(int k=i;k<=n-1;k++){
        if(isPal(i,k,s)){
            int noc=1+f(k+1,n,s);
            mini=min(mini,noc);
        }
    }
    return dp[i]=mini;
}
    int minCut(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n,s)-1;
    }
};