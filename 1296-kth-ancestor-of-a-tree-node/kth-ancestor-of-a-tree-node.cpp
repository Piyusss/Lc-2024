class TreeAncestor {
public:
    int up[50000+5][30];

    int binaryLifting(int node,int k){
        for(int bit=0;bit<=29;bit+=1){
            if((1<<bit) & k){
                if(node!=-1) node=up[node][bit];
            }
        }
        return node;
    }

    TreeAncestor(int n, vector<int>& parent){
        memset(up,-1,sizeof(up));
        for(int i=1;i<=n-1;i+=1) up[i][0]=parent[i];

        for(int l=1;l<=29;l+=1){
            for(int v=0;v<=n-1;v+=1){
                if(up[v][l-1]!=-1) up[v][l]=up[up[v][l-1]][l-1];
            }
        }

    }
    
    int getKthAncestor(int node, int k){
        return binaryLifting(node,k);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */