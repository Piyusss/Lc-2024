class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int m=edges.size();
        int n=colors.size();

        vector<int>adjList[n];
        vector<int>inDegree(n);

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            inDegree[v]++;
        }


        queue<int>q;
        int res=0;
        int sizeOfToposortObtained=0;
        vector<vector<int>>grid(n,vector<int>(26));
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
                grid[i][colors[i]-'a']++;
            }
        }


        while(!q.empty()){
            auto node=q.front();
            sizeOfToposortObtained++;
            q.pop();

            res=max(res,grid[node][colors[node]-'a']);

            for(auto &it:adjList[node]){
                for(int i=0;i<26;i++){
                    grid[it][i]=max(grid[it][i],grid[node][i] + (colors[it]-'a'==i));
                }

                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(sizeOfToposortObtained!=n)return -1;
        return res;

    }
};