class Solution {
public:

    int dp[100];

    int f1(vector<int>&nums,int idx){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(nums[idx]+f1(nums,idx+2) , 0+f1(nums,idx+1));
    }

    int f2(vector<int>&nums,int idx){
        if(idx>=nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(nums[idx]+f2(nums,idx+2) , 0+f2(nums,idx+1));
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        
        memset(dp,-1,sizeof(dp));
        
        int _1st=f1(nums,1);
        memset(dp,-1,sizeof(dp));
        int _2nd=f2(nums,0);

        return max(_1st,_2nd);
    }
};