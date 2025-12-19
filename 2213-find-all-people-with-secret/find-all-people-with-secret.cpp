class Solution{
public:
    vector<int>findAllPeople(int n, vector<vector<int>>& m, int f) {
        map<int,vector<pair<int,int>>>tm;

        for(auto &e:m) tm[e[2]].push_back({e[0],e[1]});
        vector<int>k(n);

        k[0]=k[f]=1;

        for(auto &x:tm){
            unordered_map<int,vector<int>>g;
            for(auto &p:x.second){
                g[p.first].push_back(p.second);
                g[p.second].push_back(p.first);
            }

            queue<int>q;
            unordered_set<int>s;
            for(auto &p:x.second){
                if(k[p.first]) s.insert(p.first);
                if(k[p.second]) s.insert(p.second);
            }

            for(int v:s) q.push(v);

            while(!q.empty()){
                int u=q.front();
                q.pop();

                for(int v:g[u]){
                    if(!k[v]){
                        k[v]=1;
                        q.push(v);
                    }
                }
            }
        }

        vector<int>r;
        for(int i=0;i<n;i++) if(k[i]) r.push_back(i);
        return r;
    }
};