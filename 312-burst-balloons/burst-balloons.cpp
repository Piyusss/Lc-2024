class Solution {
public:

int dp[302][302];

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        memset(dp,0,sizeof(dp));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j)continue;
                int maxi=-1e9;
                for(int ind=i;ind<=j;ind++){
                    int cost=nums[ind]*nums[i-1]*nums[j+1]
                                +dp[i][ind-1]
                                +dp[ind+1][j];
                    maxi=max(maxi,cost);
                }
                dp[i][j]=maxi;
            }
        }

        return dp[1][n];
    }
};