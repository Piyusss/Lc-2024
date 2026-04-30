const int INF=1e9;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& a,int k) {
        int m=a.size(),n=a[0].size();

        vector<vector<vector<int>>>d(m,vector<vector<int>>(n,vector<int>(k+1,-1)));

        function<int(int,int,int)> f=[&](int i,int j,int k){
            if(i<0||j<0||k<0) return -INF;
            if(i==0&&j==0) return 0;

            if(d[i][j][k]!=-1) return d[i][j][k];

            int c=a[i][j]>0, nk=k-c, u=f(i-1,j,nk), l=f(i,j-1,nk), best=max(u,l);
            if(best<0) return d[i][j][k]=-INF;

            return d[i][j][k]=best+a[i][j];
        };

        int r=f(m-1,n-1,k);
        return r<0 ? -1 : r;
    }
};