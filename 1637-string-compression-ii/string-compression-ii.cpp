int dp[101][27][101][101];

class Solution {
public:

int f(string &s,int k,int idx,int prev_ch,int freq){
    if(k<0)return INT_MAX;
    if(idx>=s.size())return 0;

    if(dp[idx][prev_ch][freq][k]!=-1)return dp[idx][prev_ch][freq][k];

    int to_del=0+f(s,k-1,idx+1,prev_ch,freq);
    int to_keep=0;

    if(s[idx]-'a' != prev_ch){
        to_keep=1+f(s,k,idx+1,s[idx]-'a',1);
    }
    else{
        int to_add=0;
        if(freq==1 || freq==9 || freq==99)to_add=1;
        to_keep=to_add+f(s,k,idx+1,prev_ch,freq+1);
    }

    return dp[idx][prev_ch][freq][k]= min(to_del,to_keep);
}
    int getLengthOfOptimalCompression(string s, int k){
        memset(dp,-1,sizeof(dp));
        return f(s,k,0,26,0);
    }
};