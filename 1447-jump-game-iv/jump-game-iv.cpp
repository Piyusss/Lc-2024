class Solution {
public:
    int minJumps(vector<int>& a) {
        int n=a.size();
        if(n==1) return 0;

        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++) mp[a[i]].push_back(i);

        vector<int>vis(n);
        vis[0]=1;

        queue<int>q;
        q.push(0);

        int step=0;

        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                int u=q.front();
                q.pop();

                if(u==n-1) return step;

                if(u+1<n && !vis[u+1]){
                    vis[u+1]=1;
                    q.push(u+1);
                }

                if(u-1>=0 && !vis[u-1]){
                    vis[u-1]=1;
                    q.push(u-1);
                }

                for(auto &v:mp[a[u]]){
                    if(v!=u && !vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }

                mp[a[u]].clear();
            }

            step++;
        }

        return -1;
    }
};