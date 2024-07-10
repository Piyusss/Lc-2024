class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        int maxi=1;
        vector<int>dp(n+1,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};