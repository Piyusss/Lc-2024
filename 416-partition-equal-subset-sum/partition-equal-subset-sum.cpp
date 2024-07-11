class Solution {
public:
bool f(int ind,int target,vector<int> &arr,vector<vector<int>>& dp){
    if(target==0)return true;
    if(ind==0)return (target==arr[ind]);
    if(dp[ind][target]!=-1)return dp[ind][target];

    bool notTake=f(ind-1,target,arr,dp);
    bool Take=false;
    if(target>=arr[ind]) Take=f(ind-1,target-arr[ind],arr,dp);

    return dp[ind][target]=(Take || notTake);
}
    bool canPartition(vector<int>& arr) {
        int n=arr.size();int k=0;
        for(int i=0;i<n;i++)k+=arr[i];
        if(k&1)return 0;
        k/=2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1,k,arr,dp);
    }
};