class Solution {
public:

    int dp[100];

    int f(vector<int>&nums,int idx){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(nums[idx]+f(nums,idx+2) , 0+f(nums,idx+1));
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(nums,0);
    }
};