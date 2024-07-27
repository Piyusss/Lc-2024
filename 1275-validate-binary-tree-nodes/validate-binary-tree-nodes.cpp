class DisjointSet {
    public:
    vector<int> rank, parent, sizee;
    int flag;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sizee.resize(n + 1,1);
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

    bool unionBySize(int u, int v,int child_ka_parent,int parent_ka_parent ) {

        if (child_ka_parent != v)
            return false;

        if (parent_ka_parent == child_ka_parent)
            return false;

        parent[v]=u;
        flag--;
        return true;
    }
    bool isSingleComponentLeftOrNot(){
        return flag==1;
    }
};



class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild){
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1 && !ds.unionBySize(i,leftChild[i],ds.findUPar(leftChild[i]),ds.findUPar(i))) return 0;
            if(rightChild[i]!=-1 && !ds.unionBySize(i,rightChild[i],ds.findUPar(rightChild[i]),ds.findUPar(i))) return 0;
        }
        return ds.isSingleComponentLeftOrNot();
    }
};