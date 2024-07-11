class Solution {
public:

int f(int ind,int target,vector<int>& arr , vector<vector<int>>&dp){
	if(ind==0){
        if(target==0 && arr[0]==0)return 2;
        if(target==0 && arr[0]!=0)return 1;
        if(target==arr[0])return 1;
        return 0;
    }

	if(dp[ind][target]!=-1)return dp[ind][target];
	
    int notTaken=f(ind-1,target,arr,dp);
    int taken=0;
    if(arr[ind]<=target)taken=f(ind-1,target-arr[ind],arr,dp);

    return dp[ind][target]=(notTaken+taken);
}


    int findTargetSumWays(vector<int>& nums, int d){
        int n=nums.size();
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        if(d>totalsum || (totalsum-d)&1 )return 0;
        int target=(totalsum-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return f(n-1,target,nums,dp);
    }
};