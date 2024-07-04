class Solution {
public:
int f(vector<int>&nums,int ind,vector<int>&dp){
    if(ind==0)return nums[0];
    if(ind<0)return 0;

    if(dp[ind]!=-1)return dp[ind];

    int pick=nums[ind]+f(nums,ind-2,dp);
    int notPick=0+f(nums,ind-1,dp);
    return dp[ind]=max(pick,notPick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1)return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=nums.size()-1)temp2.push_back(nums[i]);
        }
        vector<int>dp1(n-1,-1);vector<int>dp2(n-1,-1);
        return max(f(temp1,n-2,dp1),f(temp2,n-2,dp2));
    }
};