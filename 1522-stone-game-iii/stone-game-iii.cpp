class Solution {
public:

int n;
int dp[50001];

int f(int idx,vector<int>& nums){
    if(idx>=n)return 0;

    if(~dp[idx])return dp[idx];

    int res=INT_MIN;
    res=max(res, (nums[idx]) - f(idx+1,nums));
    if(idx+1<n)res=max(res, (nums[idx] + nums[idx+1]) - f(idx+2,nums));
    if(idx+2<n)res=max(res, (nums[idx] + nums[idx+1] + nums[idx+2]) - f(idx+3,nums));

    return dp[idx]= res;

}
    string stoneGameIII(vector<int>& nums){
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        int maxi_Of_Alice=f(0,nums);
        return maxi_Of_Alice==0 ? "Tie" : (maxi_Of_Alice>0 ? "Alice" : "Bob");
    }
};