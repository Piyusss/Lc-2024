class Solution {
public:
int n;
int dp[201][1001];
int f(int idx,int t,vector<int>nums){
    if(t==0)return 1;
    if(t<0 || idx>=n)return 0;
    if(dp[idx][t]!=-1)return dp[idx][t];

    int take=f(0,t-nums[idx],nums);
    int not_take=f(idx+1,t,nums);

    return dp[idx][t]=take+not_take;
}
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(0,target,nums);
    }
};