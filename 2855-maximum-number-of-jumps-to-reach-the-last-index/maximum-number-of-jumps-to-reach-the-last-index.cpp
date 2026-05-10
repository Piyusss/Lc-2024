class Solution {
public:

    int n;
    vector<int>dp;

    int f(int i,vector<int>&a,int t){
        if(i==n-1) return 0;
        if(dp[i]!=-2) return dp[i];

        int r=-1e9;
        for(int j=i+1;j<n;j++) if(abs(a[j]-a[i])<=t) r=max(r,1+f(j,a,t));
        return dp[i]=r;
    }

    int maximumJumps(vector<int>& a,int t) {
        n=a.size();
        
        dp.assign(n,-2);
        int r=f(0,a,t);

        return (r<0)?-1:r;
    }
};