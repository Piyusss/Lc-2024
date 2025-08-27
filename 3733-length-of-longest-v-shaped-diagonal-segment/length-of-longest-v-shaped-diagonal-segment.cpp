class Solution{
public:

    int r,c;
    vector<vector<int>> a;
    int d[4][2]={{1,1},{1,-1},{-1,-1},{-1,1}};
    int dp[501][501][4][2];

    int f(int x,int y,int k,bool t,int v){
        int nx=x+d[k][0],ny=y+d[k][1];
        if(nx<0||ny<0||nx>=r||ny>=c||a[nx][ny]!=v) return 0;

        if(dp[nx][ny][k][t]!=-1) return dp[nx][ny][k][t];

        int ans=f(nx,ny,k,t,2-v);
        if(t) ans=max(ans,f(nx,ny,(k+1)%4,false,2-v));

        return dp[nx][ny][k][t]=ans+1;
    }

    int lenOfVDiagonal(vector<vector<int>>& g){
        a=g;
        r=a.size();
        c=a[0].size();

        memset(dp,-1,sizeof(dp));
        int res=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==1){
                    for(int k=0;k<4;k++){
                        res=max(res,f(i,j,k,1,2)+1);
                    }
                }
            }
        }

        return res;
    }
};
