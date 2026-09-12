using ll=long long;

class Solution {
public:

    vector<ll>f(vector<vector<int>>&a,int i,int c,vector<vector<vector<ll>>>&dp){
        int n=a.size();

        if(i==n||c==4) return {0};
        if(!dp[i][c].empty()) return dp[i][c];

        auto x=f(a,i+1,c,dp);
        auto y=f(a,bs(a,i),c+1,dp);

        y[0]+=a[i][2];
        y.push_back(i);

        if(x[0]!=y[0]) return dp[i][c]=x[0]>y[0]?x:y;
        return dp[i][c]=better(x,y,a)?x:y;
    }

    bool better(vector<ll>&a,vector<ll>&b,vector<vector<int>>&v){
        vector<int>x,y;

        for(int i=1;i<a.size();i++) x.push_back(v[a[i]][3]);
        for(int i=1;i<b.size();i++) y.push_back(v[b[i]][3]);

        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        return x<y;
    }

    int bs(vector<vector<int>>&a,int x){
        int n=a.size(),i=x+1,j=n-1;

        while(i<=j){
            int m=i+(j-i)/2;
            if(a[m][0]>a[x][1]) j=m-1;
            else i=m+1;
        }
        return i;
    }

    vector<int> maximumWeight(vector<vector<int>>& a) {
        int n=a.size();

        for(int i=0;i<n;i++) a[i].push_back(i);
        sort(a.begin(),a.end());
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(4));

        auto x=f(a,0,0,dp);
        reverse(x.begin(),x.end());
        x.pop_back();

        vector<int>ans;
        for(auto &i:x) ans.push_back(a[i][3]);
        sort(ans.begin(),ans.end());

        return ans;
    }
};