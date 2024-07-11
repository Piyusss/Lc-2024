class Solution {
public:

int dp[502];

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(dp,0,sizeof(dp));
        
        for(int idx=n-1;idx>=0;idx--){
            int len=0,maxi=-1e9,maxAns=-1e9;
            for(int j=idx;j<min(idx+k,n);j++){
                len++;
                maxi=max(maxi,arr[j]);
                maxAns=max(maxAns,(len*maxi)+dp[j+1]);
            }
            dp[idx]=maxAns;
        }

        return dp[0];
    }
};