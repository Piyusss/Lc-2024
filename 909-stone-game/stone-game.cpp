class Solution {
public:

int ans=0;
int dp[2][502][502];
int f(vector<int>& nums,bool isAlice,int i,int j,int point_alice,int point_bob){
    if(i>j){
        if(point_alice>point_bob)ans=1;
        return 0;
    }

    if(dp[isAlice][i][j]!=-1)return dp[isAlice][i][j];
    
    if(isAlice){
        int a=nums[i]+f(nums,0,i+1,j,0,0);
        int b=nums[j]+f(nums,0,i,j-1,0,0);
        point_alice=max(a,b);
    }
    else if(!isAlice){
        int a=nums[i]+f(nums,1,i+1,j,0,0);
        int b=nums[j]+f(nums,1,i,j-1,0,0);
        point_bob=max(a,b);
    }
    return dp[isAlice][i][j] = (isAlice) ? point_alice : point_bob;
}
    bool stoneGame(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        f(nums,1,0,n-1,0,0);
        return ans==0;
    }
};