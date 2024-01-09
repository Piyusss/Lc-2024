class Solution {
public:
bool dfs(int start,vector<int>adj[] ,vector<int>&col ,int x){
        col[start]=x;
        for(auto it:adj[start]){
            if(col[it]==-1){
                if(dfs(it,adj,col,!x)==false)return false;
            }
            else if(col[it]==col[start])return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(auto it:dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        //now
        vector<int>col(n+1,-1);
        for(int i=1 ; i<=n ; i++){
	        if(col[i]==-1){
	            if(dfs(i,adj,col,0)==false)return false;
	        }
	    }
	    return true;
    }
};