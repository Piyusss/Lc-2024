class Solution {
public:

int dp[21][21];

int f(int i,int j,vector<int>& nums){
    if(i>j)return 0;
    if(i==j)return nums[i];

    if(~dp[i][j])return dp[i][j];

    int choose_start_idx=nums[i] + min( f(i+2,j,nums) , f(i+1,j-1,nums) ) ;
    int choose_end_idx=nums[j] + min( f(i,j-2,nums) , f(i+1,j-1,nums) ) ;

    return dp[i][j]= max(choose_start_idx,choose_end_idx);
    
}
    bool predictTheWinner(vector<int>& nums){
        memset(dp,-1,sizeof(dp));
        int bestOfPlayerA=f(0,nums.size()-1,nums);
        return bestOfPlayerA>=(accumulate(nums.begin(),nums.end(),0)-bestOfPlayerA);
    }
};