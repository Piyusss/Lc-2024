class Solution {
public:

int dp[2][101][101];
int n;

int f(vector<int>& nums,bool isAlice,int i,int M){
    if(i>=n) return 0;

    if(dp[isAlice][i][M]!=-1)return dp[isAlice][i][M];
    
    int a=0;
    int point_alice=0,point_bob=0;
    if(!isAlice)point_bob=INT_MAX;

    for(int k=1;k<=min(2*M,n-i);k++){
        a+=nums[i+k-1];
        if(isAlice)point_alice=max(point_alice,a+f(nums,0,i+k,max(M,k)));
        else point_bob=min(point_bob,f(nums,1,i+k,max(M,k)));
    }
    return dp[isAlice][i][M] = (isAlice) ? point_alice : point_bob;
}
    int stoneGameII(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(nums,1,0,1);
    }
};