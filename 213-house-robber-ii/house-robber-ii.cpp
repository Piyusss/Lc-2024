class Solution {
public:

int dp[100+1];

    int f(vector<int>& nums) {
        int n=nums.size();
        dp[0]=nums[0];
        for(int i=1;i<=n-1;i++)dp[i]=max(i>=2 ? nums[i]+dp[i-2] : nums[i] , dp[i-1]);
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1)return nums[0];

        vector<int>temp1,temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=nums.size()-1)temp2.push_back(nums[i]);
        }

        memset(dp,-1,sizeof(dp));
        int a=f(temp1);
        memset(dp,-1,sizeof(dp));
        int b=f(temp2);
        return max(a,b);
    }
};