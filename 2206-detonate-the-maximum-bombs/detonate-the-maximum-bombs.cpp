class Solution {
public:

void dfs(long long node,vector<long long>adjList[],vector<long long>& vis,long long &cnt){
    vis[node]=1;
    cnt++;

    for(auto it:adjList[node]){
        if(!vis[it]){
            dfs(it,adjList,vis,cnt);
        }
    }
}
    int maximumDetonation(vector<vector<int>>& bombs){
        long long n=bombs.size();
        vector<long long>adjList[n+1];

        for(long long i=0;i<n;i++){
            for(long long j=0;j<n;j++){
                if(i==j)continue;

                long long x1=bombs[i][0];
                long long y1=bombs[i][1];
                long long r1=bombs[i][2];

                long long x2=bombs[j][0];
                long long y2=bombs[j][1];

                long long disSquare= (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);

                if(r1*r1>=disSquare)adjList[i].push_back(j);
            }
        }

        vector<long long>vis(n+1,0);
        vector<long long>vis2=vis;
        long long res=0;
        for(long long i=0;i<n;i++){
            long long cnt=0;
            dfs(i,adjList,vis,cnt);
            res=max(res,cnt);
            vis=vis2;
        }

        return res;
    }
};