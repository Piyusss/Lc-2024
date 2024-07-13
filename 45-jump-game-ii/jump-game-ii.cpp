class Solution {
public:

int dp[10000+2];

    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        memset(dp,0,sizeof(dp));
        
        for(int idx=n-2;idx>=0;idx--){
            int mini=n+1;
            for(int i=1;i<=nums[idx];i++){
                int jumps=1+(idx+i<=n-1 ? dp[idx+i] : 0);
                mini=min(mini,jumps);
            }
           dp[idx]=mini;
        }

        return dp[0];
    }
};