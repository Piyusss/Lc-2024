class Solution {
public:

    int m,n;
    vector<vector<vector<int>>>dp;

    bool f(vector<vector<char>>&a,int r,int c,int x){
        if(r>=m||c>=n) return 0;

        x+=a[r][c]=='('?1:-1;

        if(x<0) return 0;
        if(r==m-1&&c==n-1) return x==0;
        if(dp[r][c][x]!=-1) return dp[r][c][x];

        return dp[r][c][x]=f(a,r+1,c,x) || f(a,r,c+1,x);
    }

    bool hasValidPath(vector<vector<char>>& a) {
        m=a.size(),n=a[0].size();

        if((m+n-1)%2) return 0;
        if(a[0][0]==')' || a[m-1][n-1]=='(') return 0;

        dp.assign(m,vector<vector<int>>(n,vector<int>(m+n+1,-1)));
        return f(a,0,0,0);
    }
};