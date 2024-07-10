class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int canbuy=0;canbuy<=1;canbuy++){
                for(int cap=1;cap<=2;cap++){
                    int profit=0;
                    if(canbuy==1){
                        profit=max((-prices[ind]+dp[ind+1][0][cap]),
                        (0+dp[ind+1][1][cap]));
                    }
                    else{
                        profit=max((prices[ind]+dp[ind+1][1][cap-1]),
                        (0+dp[ind+1][0][cap]));
                    }
                    dp[ind][canbuy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};