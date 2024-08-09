class Solution {
public:

int dp[100+1][100+1];

int f(int i,int j,vector<int>&cuts){
    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    
    int mini=INT_MAX;
    for(int k=i;k<=j;k++){
        int cost=cuts[j+1]-cuts[i-1]
                   +f(i,k-1,cuts)
                   +f(k+1,j,cuts);
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