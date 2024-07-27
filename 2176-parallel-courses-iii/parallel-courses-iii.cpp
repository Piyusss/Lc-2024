class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adjList[n];
        vector<int>inDegree(n,0);
        vector<int>timeCopy(n,0);


        for(auto it:relations){
            int u=it[0]-1;
            int v=it[1]-1;
            adjList[u].push_back(v);
            inDegree[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
                timeCopy[i]=time[i];
            }
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            for(auto it:adjList[node]){
                timeCopy[it]=max(timeCopy[it],timeCopy[node]+time[it]);
                inDegree[it]--;
                if(inDegree[it]==0)q.push(it);
            }
        }

        return *max_element(timeCopy.begin(),timeCopy.end());
    }
};