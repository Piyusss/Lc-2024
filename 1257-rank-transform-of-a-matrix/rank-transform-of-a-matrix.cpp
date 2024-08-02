class DisjointSet{
    vector<int>rank,size;
    unordered_map<int,int>parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i=0 ; i<=n ; i++){
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v) {
        if (parent.count(u)==0) parent[u]=u;
        if (parent.count(v)==0) parent[v]=v;
        int pu=findUPar(u),pv=findUPar(v);
        if (pu!=pv) parent[pu]=pv;
    }

    unordered_map<int,vector<int>>allGroups(){
        unordered_map<int,vector<int>>groups;
        for(auto &it:parent){
            int u=it.first;
            groups[findUPar(u)].push_back(u);
        }
        return groups;
    }

    int findSize(int ulp){
        return size[ulp];
    }

};


class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        map<int,vector<pair<int,int>>>mp;
        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                mp[matrix[r][c]].push_back({r,c});
            }
        }

        vector<int> rank(n+m);
        for(auto &it: mp){
            DisjointSet ds(n+m);
            for(auto &it2: it.second){
                int r=it2.first;
                int c=it2.second;
                ds.unionBySize(r,c+n);
            }

            for(auto &unmp: ds.allGroups()){
                auto group=unmp.second;
                int maxRank=0;
                for (auto k:group) maxRank=max(maxRank,rank[k]);
                for (auto k:group) rank[k]=maxRank+1;
            }

            for(auto &it3:it.second){
                int r=it3.first;
                int c=it3.second;
                ans[r][c]=rank[r]; 
            }
        }
        
        return ans;
    }
};