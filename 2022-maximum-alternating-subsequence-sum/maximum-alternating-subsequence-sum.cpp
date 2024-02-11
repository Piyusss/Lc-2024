class Solution {
public:
    long long f(vector<int>& nums,long long n,int idx,bool flag
    ,vector<vector<long long>>&dp){
        if(idx>=n)return 0;

        if(dp[idx][flag]!=-1)return dp[idx][flag];
        long long skip=f(nums,n,idx+1,flag,dp);
        long long val=nums[idx];
        if(flag==false)val=-val;
        long long take=val+f(nums,n,idx+1,!flag,dp);
        return dp[idx][flag]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        long long n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return f(nums,n,0,true,dp);
    }
};