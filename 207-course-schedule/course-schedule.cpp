class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        int m=p.size();

        vector<int>adjList[n],inDeg(n);
        for(int i=0;i<m;i++){
            auto it=p[i];
            adjList[it[1]].push_back(it[0]);
            inDeg[it[0]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++) if(inDeg[i]==0) q.push(i);

        int cnt=0;
        while(!q.empty()){
            auto node=q.front();
            cnt+=1;
            q.pop();

            for(auto &c:adjList[node]){
                inDeg[c]-=1;
                if(inDeg[c]==0) q.push(c);
            }
        }

        return (cnt==n)?1:0;
    }
};