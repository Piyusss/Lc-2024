class Solution {
public:
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
	    int m=grid[0].size();

	    queue<pair<pair<int,int>,int>>q;
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>ans(n,vector<int>(m,1e9));//dont hamper given data
	    
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<m ; j++){
	            if(!vis[i][j] && grid[i][j]==0){
	                q.push({{i,j},0});
                    vis[i][j]=1;
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int qr=q.front().first.first;
	        int qc=q.front().first.second;
	        int step=q.front().second;

	        q.pop();
	        ans[qr][qc]=min(ans[qr][qc],step);
	        
	        for(auto it:dir){
                int nr=qr+it[0];
	            int nc=qc+it[1];
	            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
	                vis[nr][nc]=1;
	                q.push({{nr,nc},step+1});
	            }
            }
	    }
	    return ans;
    }
};