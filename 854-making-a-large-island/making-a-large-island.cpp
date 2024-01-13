class DisjointSet{
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0 ; i<=n ; i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
    private:
    bool isValid(int nr,int nc,int n){
        return nr>=0 && nr<=n-1 && nc>=0 && nc<=n-1;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};

                for(int ind=0;ind<4;ind++){
                    int nr=row+dr[ind];
                    int nc=col+dc[ind];

                    if(isValid(nr,nc,n)&&grid[nr][nc]==1){
                        ds.unionBySize(n*row+col,n*nr+nc);
                    }
                }
            }
        }
        //now
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};

                set<int>components;
                for(int ind=0;ind<4;ind++){
                    int nr=row+dr[ind];
                    int nc=col+dc[ind];

                    if(isValid(nr,nc,n)){
                        if(grid[nr][nc]==1){
                            components.insert(ds.findUPar(nr*n+nc));
                        }
                    }
                }
                int sizeTotal=0;
                for(auto it:components){
                    sizeTotal+=ds.size[it];
                }
                mx=max(mx,sizeTotal+1);
            }
        }
        int cnt=0;
        for(auto it:grid){
            for(auto itt:it){
                if(itt==1)cnt++;
            }
        }
        if(cnt==n*n)return n*n;
        return mx;
    }
};