class Solution {
public:

int dp[10000+2];

bool f(int idx,vector<int>& nums,int n){
    if(idx==n-1)return 1;
    if(idx>=n)return 0;

    if(dp[idx]!=-1)return dp[idx];

    for(int i=1;i<=nums[idx];i++){
        int new_idx=idx+i;
        if(f(new_idx,nums,n))return dp[idx]=1;
    }
    return dp[idx]=0;
}
    bool canJump(vector<int>& nums){
        int n=nums.size();
        if(n==1)return 1;
        memset(dp,-1,sizeof(dp));
        return f(0,nums,n);
    }
};