class Solution {
public:

int dp[300+1][300+1];

int f(int i,int j,vector<int> &nums){
    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int maxi=INT_MIN;
    for(int k=i;k<=j;k++){
        int cost=nums[k]*nums[i-1]*nums[j+1]
                    +f(i,k-1,nums)
                    +f(k+1,j,nums);
        maxi=max(maxi,cost);
    }
    return dp[i][j]=maxi;
}
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        memset(dp,-1,sizeof(dp));

        return f(1,n,nums);
    }
};