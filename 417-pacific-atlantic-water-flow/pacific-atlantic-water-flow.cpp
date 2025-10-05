class Solution {
public:

bool flag1,flag2;
int n,m;

vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vector<vector<int>>& heights,int i,int j,vector<vector<int>>&vis){
    vis[i][j]=1;

    if(i==0 || j==0)flag1=1;
    if(i==n-1 || j==m-1)flag2=1;

    for(auto &it:dir){
        int new_i=i+it[0];
        int new_j=j+it[1];

        if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && !vis[new_i][new_j] && heights[new_i][new_j]<=heights[i][j]){
            dfs(heights,new_i,new_j,vis);
        }
    }

}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();

        vector<vector<int>>res;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                dfs(heights,i,j,vis);
                if(flag1 && flag2) res.push_back({i,j});

                flag1=0,flag2=0;
                vis.assign(n,vector<int>(m,0));
            }
        }

        return res;
    }
};