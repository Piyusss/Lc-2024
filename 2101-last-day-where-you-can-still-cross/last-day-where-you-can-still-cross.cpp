class Solution {
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

    bool ok(int r,int c,vector<vector<int>>&a,int d){
        vector<vector<int>>g(r,vector<int>(c));
        for(int i=0;i<d;i++) g[a[i][0]-1][a[i][1]-1]=1;

        queue<pair<int,int>>q;
        for(int j=0;j<c;j++){
            if(!g[0][j]){
                g[0][j]=1;
                q.push({0,j});
            }
        }

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            if(x==r-1)return 1;

            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];

                if(nx>=0 && nx<r && ny>=0 && ny<c && !g[nx][ny]){
                    g[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }

        return 0;
    }

public:
    int latestDayToCross(int r, int c, vector<vector<int>>&a) {
        int l=1,h=a.size(),res=0;

        while(l<=h){
            int m=l+(h-l)/2;
            if(ok(r,c,a,m)) res=m,l=m+1;
            else h=m-1;
        }

        return res;
    }
};