class Solution {
public:

int dp[101][101];

int f(string &s,int l,int r){
    if(l==r)return 1;
    if(l>r)return 0;

    if(dp[l][r]!=-1)return dp[l][r];

    int i=l+1;
    while(i<=r && s[i]==s[l])i++;

    int oneGo=1+f(s,i,r);

    int greed=INT_MAX;
    for(int k=i;k<=r;k++){
        if(s[k]==s[l]){
            int part=f(s,i,k-1) + f(s,k,r);
            greed=min(greed,part);
        }
    }

    return dp[l][r] = min(oneGo,greed);
}
    int strangePrinter(string s){
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return f(s,0,n-1);
    }
};