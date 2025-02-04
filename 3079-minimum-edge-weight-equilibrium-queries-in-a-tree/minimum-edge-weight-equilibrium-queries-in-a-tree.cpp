class Tree {
private:
    const int root = 0;
    const vector<int>* adjList;
    const int log2dist;
    vector<int> par;
    vector<vector<int>> pow2ends;
    vector<int> depth;

    void process(int at, int prev) {
        par[at] = prev;
        depth[at] = depth[prev] + 1;
        for (int n : adjList[at]) {
            if (n != prev) {
                process(n, at);
            }
        }
    }

public:
    Tree(const vector<int>* adjList, int size)
        : adjList(adjList), log2dist(ceil(log2(size))), par(size),
          pow2ends(size, vector<int>(log2dist + 1)), depth(size) {
        par[root] = -1;
        depth[root] = 0;
        process(root, root);

        for (int n = 0; n < size; n++) {
            pow2ends[n][0] = par[n];
        }

        for (int p = 1; p <= log2dist; p++) {
            for (int n = 0; n < size; n++) {
                int halfway = pow2ends[n][p - 1];
                pow2ends[n][p] = (halfway == -1) ? -1 : pow2ends[halfway][p - 1];
            }
        }
    }

    int kth_parent(int n, int k) {
        if (k >= par.size()) return -1;
        int at = n;
        for (int pow = 0; pow <= log2dist; pow++) {
            if ((k & (1 << pow)) != 0) {
                at = pow2ends[at][pow];
                if (at == -1) break;
            }
        }
        return at;
    }

    int lca(int n1, int n2) {
        if (depth[n1] < depth[n2]) swap(n1, n2);
        n1 = kth_parent(n1, depth[n1] - depth[n2]);
        if (n1 == n2) return n2;

        for (int i = log2dist; i >= 0; i--) {
            if (pow2ends[n1][i] != pow2ends[n2][i]) {
                n1 = pow2ends[n1][i];
                n2 = pow2ends[n2][i];
            }
        }
        return pow2ends[n1][0];
    }

    int dist(int n1, int n2) {
        return depth[n1] + depth[n2] - 2 * depth[lca(n1, n2)];
    }
};


class Solution {
public:

int dp[10000][27];
vector<int>g[10000];
int height[10000];
vector<int>res;
vector<pair<int,int>>gw[10000];

void dfs(int node,int p){
    for(auto &c:gw[node]){
        int child=c.first;
        int wt=c.second;

        if(child != p){
            height[child]=height[node]+1;
            for(int j=1;j<=26;j++){
                dp[child][j]=dp[node][j];
            }
            dp[child][wt] += 1;
            dfs(child,node);
        }
    }
}

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for(auto &c:edges){
            int u=c[0];
            int v=c[1];
            int w=c[2];
            g[u].push_back(v);
            g[v].push_back(u);
            
            gw[u].push_back({v,w});
            gw[v].push_back({u,w});
        }

        Tree tree(g,n);
        dfs(0,-1);

        for(auto &c:queries){
            int ai=c[0];
            int bi=c[1];

            int lcaOfAiandBi=tree.lca(ai,bi);

            int totalEdgesBwAiandBi= height[ai] + height[bi] - 2*(height[lcaOfAiandBi]);

            int maxi=0;
            for(int j=1;j<=26;j++){
                int freq=dp[ai][j] + dp[bi][j] - 2*(dp[lcaOfAiandBi][j]);
                maxi=max(maxi,freq);
            }

            res.push_back(totalEdgesBwAiandBi - maxi);
        }

        return res;
    }
};