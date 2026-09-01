class Solution {
public:
    int minMoves(vector<string>& a,int e) {
        int m=a.size(),n=a[0].size();

        vector<vector<int>>id(m,vector<int>(n,-1));
        int k=0,sr=0,sc=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                else if(a[i][j]=='L'){
                   id[i][j]=k++;
                }
            }
        }

        if(!k) return 0;
        int mask=(1<<k)-1;

        vector<vector<vector<int>>>best(
            m,vector<vector<int>>(n,vector<int>(1<<k,-1))
        );

        struct State{
            int r,c,m,e,d;
        };

        queue<State>q;

        best[sr][sc][0]=e;
        q.push({sr,sc,0,e,0});

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        while(!q.empty()){
            auto x=q.front();
            q.pop();

            for(int d=0;d<4;d++){
                int r=x.r+dr[d],c=x.c+dc[d];
                if(r<0||r>=m||c<0||c>=n||a[r][c]=='X') continue;

                int ne=x.e-1;
                if(ne<0) continue;

                int nm=x.m;

                if(a[r][c]=='R') ne=e;
                if(a[r][c]=='L') nm|=1<<id[r][c];

                if(nm==mask) return x.d+1;
                if(ne<=best[r][c][nm]) continue;

                best[r][c][nm]=ne;
                q.push({r,c,nm,ne,x.d+1});
            }
        }

        return -1;
    }
};