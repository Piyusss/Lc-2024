class Solution {
public:

int dp[102][102];

int f(int i,int j,vector<int>& cuts){
    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    
    int mini=1e9;
    for(int ind=i;ind<=j;ind++){
        int cost=cuts[j+1]-cuts[i-1]
                   +f(i,ind-1,cuts)
                   +f(ind+1,j,cuts);
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));

        return f(1,c,cuts);
    }
};