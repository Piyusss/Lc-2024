class Solution {
public:

    int dp[501][501];
    vector<int>p;

    int f(vector<int>&a,int l,int r){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        int x=0;

        for(int i=l;i<r;i++){
            int a1=p[i+1]-p[l];
            int a2=p[r+1]-p[i+1];

            if(a1<a2) x=max(x,a1+f(a,l,i));
            else if(a1>a2) x=max(x,a2+f(a,i+1,r));
            else x=max(x,a1+max(f(a,l,i),f(a,i+1,r)));
        }

        return dp[l][r]=x;
    }

    int stoneGameV(vector<int>& a) {
        int n=a.size();

        p.assign(n+1,0);
        for(int i=0;i<n;i++) p[i+1]=p[i]+a[i];

        memset(dp,-1,sizeof(dp));
        return f(a,0,n-1);
    }
};