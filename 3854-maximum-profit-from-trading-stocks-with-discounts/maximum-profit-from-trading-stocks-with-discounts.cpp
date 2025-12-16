class Solution {

    vector<vector<int>>g;
    vector<vector<vector<int>>>d;

    void go(vector<int>&a,vector<int>&b,int u){
        int B=d[u].size();
        vector<int>x(B),y(B),z;

        for(int &v:g[u]){
            go(a,b,v);
            z.assign(B,0);
            for(int i=0;i<B;i++) for(int j=0;j<=i;j++) z[i]=max(z[i],x[i-j]+d[v][j][1]);

            x.swap(z);
            z.assign(B,0);
            for(int i=0;i<B;i++) for(int j=0;j<=i;j++) z[i]=max(z[i],y[i-j]+d[v][j][0]);

            y.swap(z);
        }

        int p=a[u-1],f=b[u-1],h=p>>1;
        for(int i=0;i<B;i++){
            d[u][i][0]=max(y[i],i>=p?max(0,f-p+x[i-p]):0);
            d[u][i][1]=max(y[i],i>=h?max(0,f-h+x[i-h]):0);
        }
    }

public:
    int maxProfit(int n, vector<int>& a, vector<int>& b, vector<vector<int>>& e, int k) {
        g.assign(n+1,{});

        for(auto &v:e)g[v[0]].push_back(v[1]);

        d.assign(n+1,vector<vector<int>>(k+1,vector<int>(2)));
        go(a,b,1);

        return d[1][k][0];
    }
};