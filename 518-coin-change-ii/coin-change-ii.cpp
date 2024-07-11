class Solution {
public:
int findWays(vector<int>& arr, int k){
	int n=arr.size();
	vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    for(int tar=0;tar<=k;tar++)if(tar%arr[0]==0)dp[0][tar]=1;

	for(int ind=1;ind<=n-1;ind++)for(int target=0;target<=k;target++)dp[ind][target]=dp[ind-1][target] + ( arr[ind]<=target ? dp[ind][target-arr[ind]] : 0);
	return dp[n-1][k];
}

    int change(int amount, vector<int>& coins) {
        return findWays(coins,amount);
    }
};