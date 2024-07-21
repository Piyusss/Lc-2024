class Solution {
public:

vector<int> dfs(int V, vector<int> adj[]){

	    vector<int>indegree(V+1);
	    vector<int>ans;
	    for(int i=1 ; i<=V ; i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=1 ; i<=V ; i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0)q.push(it);
	        }
	    }
	    if(ans.size()==V) return ans;
        else return {};
	}

    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>ans(k,vector<int>(k,0));

        vector<int>adjListRow[k+1];
        for(auto& it:rowConditions){
            int u=it[0];
            int v=it[1];
            adjListRow[u].push_back(v);
        }

        vector<int>adjListCol[k+1];
        for(auto& it:colConditions){
            int u=it[0];
            int v=it[1];
            adjListCol[u].push_back(v);
        }

        vector<int>validTopoRow=dfs(k,adjListRow);
        vector<int>validTopoCol=dfs(k,adjListCol);

        if(validTopoRow.size()==0 || validTopoCol.size()==0)return {};

        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(validTopoRow[i]==validTopoCol[j])ans[i][j]=validTopoCol[j];
            }
        }

        return ans;
    }
};