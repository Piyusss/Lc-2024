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
};

class Solution {
public:

bool isSimilar(string X,string Y){
    int n=X.size();
    
    int dif=0;
    for(int i=0;i<n;i++){
        if(X[i]!=Y[i])dif++;
    }

    if(dif==0 || dif==2)return 1;
    return 0;
}
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size(); 

        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string s1=strs[i];
                string s2=strs[j];

                if(isSimilar(s1,s2) && ds.findUPar(i)!=ds.findUPar(j)){
                    ds.unionBySize(i,j);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++)if(ds.findUPar(i)==i)cnt++;
        return cnt;
    }
};