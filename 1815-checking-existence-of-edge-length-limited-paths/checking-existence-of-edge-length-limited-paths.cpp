class DisjointSet {
    public:
    vector<int> rank, parent, sizee;
    int flag;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sizee.resize(n + 1);
        flag=n;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            sizee[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        flag--;
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (sizee[ulp_u] < sizee[ulp_v]) {
            parent[ulp_u] = ulp_v;
            sizee[ulp_v] += sizee[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            sizee[ulp_u] += sizee[ulp_v];
        }
        flag--;
    }
    bool isSingleComponentLeftOrNot(){
        return flag==1;
    }
};



class Solution {
public:

static bool comp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DisjointSet ds(n);

        sort(edgeList.begin(),edgeList.end(),comp);
        for(int i=0;i<queries.size();i++)queries[i].push_back(i);
        sort(queries.begin(),queries.end(),comp);

        vector<bool>ans(queries.size(),false);

        int point_edgeList=0;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            int threshold=queries[i][2];
            int idx=queries[i][3];

            while(point_edgeList<edgeList.size() && edgeList[point_edgeList][2]<threshold){
                ds.unionBySize(edgeList[point_edgeList][0],edgeList[point_edgeList][1]);
                point_edgeList++;
            }
            if(ds.findUPar(u)==ds.findUPar(v))ans[idx]=1;
        }
        return ans;
    }
};