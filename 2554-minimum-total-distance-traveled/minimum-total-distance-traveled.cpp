class Solution {
public:
    map<string,long long>mpp;
    long long dp[200][20000];
    long long f(int i,int j,vector<int>& r, vector<int> &v){
        if(i==r.size()){
            return 0LL;
        }
        if(j==v.size()){
            return 1e16;
        } 
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long ans=1e16;
        ans=min(ans,f(i,j+1,r,v));
        ans=min(ans,abs(r[i]-v[j])+f(i+1,j+1,r,v));
        return dp[i][j] = ans; 
    }
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& v) {
        sort(r.begin(),r.end());
        sort(v.begin(),v.end());
        vector<int>vv;
        for(auto it:v){
            for(int i=0;i<it[1];i++){
                vv.push_back(it[0]);
            }
        }
        memset(dp,-1,sizeof(dp));
        return f(0,0,r,vv);
    }
};