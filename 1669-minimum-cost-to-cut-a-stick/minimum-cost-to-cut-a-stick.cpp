class Solution {
public:

int dp[102][102];

    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        memset(dp,0,sizeof(dp));

        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j)continue;
                int mini=1e9;
                for(int ind=i;ind<=j;ind++){
                    int cost=cuts[j+1]-cuts[i-1]
                            +dp[i][ind-1]
                            +dp[ind+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};