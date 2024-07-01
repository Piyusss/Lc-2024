class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>indegree(n);

        vector<int>adjList[n];
        for(auto it:pre){
            adjList[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();

            for(auto it:adjList[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }

        if(ans.size()==n)return ans;
        ans.clear();
        return ans;
    }
};