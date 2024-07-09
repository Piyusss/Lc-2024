class Solution {
public:

int dp[100+1];

int f(vector<int>&nums,int idx){
    if(idx==0)return nums[0];
    if(idx<0)return 0;

    if(dp[idx]!=-1)return dp[idx];

    return dp[idx]=max(nums[idx]+f(nums,idx-2),f(nums,idx-1));
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
        int a=f(temp1,n-2);
        memset(dp,-1,sizeof(dp));
        int b=f(temp2,n-2);
        return max(a,b);
    }
};