class DisjointSet{
    vector<int>rank,parent,size;
    public:
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

    int findSize(int ulp){
        return size[ulp];
    }
};


class Solution {
public:

    int countServers(vector<vector<int>>& grid){
       int n=grid.size();
       int m=grid[0].size();

       DisjointSet ds((n*m));

       map<pair<int,int>,int>mp;

       int flag=0;
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[{i,j}]=flag++;
            }
        }

       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    //iterate on all col left se right
                    for(int k=0;k<m;k++){
                        if(j==k)continue;
                        if(grid[i][k]==1)ds.unionBySize(mp[{i,j}],mp[{i,k}]);
                    }
                    //iterate on all row upar se niche
                    for(int k=0;k<n;k++){
                        if(i==k)continue;
                        if(grid[k][j]==1)ds.unionBySize(mp[{i,j}],mp[{k,j}]);
                    }
                }
            }
        }

        int res=0;
        for(int i=0;i<n*m;i++){
            if(ds.findUPar(i)==i){
                int add=ds.findSize(i);
                if(add>=2)res+=add;
            }
        }
        return res;
    }
};