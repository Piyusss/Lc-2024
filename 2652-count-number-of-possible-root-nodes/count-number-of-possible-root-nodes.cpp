const int MAXN=1E5;

class Solution {
public:

int k,res=0;
int cnt[MAXN+1];
unordered_map<int,unordered_set<int>>mp;
vector<int>g[MAXN+1];

void preCalc(int node,int p){
    for(auto &c:g[node]){
        if(c != p){
            preCalc(c,node);
            if(mp[node].count(c)) cnt[node] += (1+cnt[c]);
            else cnt[node] += cnt[c];
        }
    }
}

void reRootDfs(int node,int p){
    if(cnt[node] >= k) res++;
    
    for(auto &c:g[node]){
        if(c != p){
            int nc=mp[node].count(c);
            int cn=mp[c].count(node);

            if(nc) cnt[node] -= (1+cnt[c]);
            else cnt[node] -= cnt[c];

            if(cn) cnt[c] += (1+cnt[node]);
            else cnt[c] += cnt[node];

            reRootDfs(c,node);

            if(cn) cnt[c] -= (1+cnt[node]);
            else cnt[c] -= cnt[node];

            if(nc) cnt[node] += (1+cnt[c]);
            else cnt[node] += cnt[c];
        }
    }
}

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int K) {
        for(auto &c:guesses){
            int u=c[0];
            int v=c[1];
            mp[u].insert(v);
        }

        for(auto &c:edges){
            int u=c[0];
            int v=c[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        k=K;
        preCalc(0,-1);
        reRootDfs(0,-1);

        return res;
    }
};