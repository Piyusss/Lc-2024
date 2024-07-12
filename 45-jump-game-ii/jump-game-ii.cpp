class Solution {
public:

int dp[10000+2];

int f(int idx,vector<int>& nums,int n){
    if(idx>=n-1)return 0;

    if(dp[idx]!=-1)return dp[idx];

    int mini=n+1;
    for(int i=1;i<=nums[idx];i++){
        int jumps=1+f(idx+i,nums,n);
        mini=min(mini,jumps);
    }

    return dp[idx]=mini;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        memset(dp,-1,sizeof(dp));
        return f(0,nums,n);
    }
};