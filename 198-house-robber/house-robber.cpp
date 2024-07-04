class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<=n-1;i++){
            int pick=nums[i];if(i>1)pick+=dp[i-2];
            int notPick=0+dp[i-1];
            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
    }
};