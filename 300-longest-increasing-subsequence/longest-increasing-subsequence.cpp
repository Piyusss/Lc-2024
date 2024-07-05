class Solution {
public:
int f(int ind,int prevInd,vector<int>arr,int n,vector<vector<int>>&dp){
    if(ind==n)return 0;
    if(dp[ind][prevInd+1]!=-1)return dp[ind][prevInd+1];

    int notPick=f(ind+1,prevInd,arr,n,dp);
    int pick=0;
    if(prevInd==-1 || arr[ind]>arr[prevInd]){
        pick=1+f(ind+1,ind,arr,n,dp);
    }
    return dp[ind][prevInd+1]=max(pick,notPick);
}
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       //now
       for(int ind=n-1;ind>=0;ind--){
           for(int prevInd=ind-1;prevInd>=-1;prevInd--){
                int notPick=dp[ind+1][prevInd+1];
                int pick=0;
                if(prevInd==-1 || arr[ind]>arr[prevInd]){
                    pick=1+dp[ind+1][ind+1];
                }
                dp[ind][prevInd+1]=max(pick,notPick);
           }
       }
       return dp[0][-1+1];
    }
};