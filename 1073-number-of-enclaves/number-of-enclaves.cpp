class Solution {
public:
int n,m;
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

void dfs(int i,int j,vector<vector<int>>&vis,
vector<vector<int>>&board){
    vis[i][j]=1;

    for(auto it:dir){
        int ni=i+it[0];
        int nj=j+it[1];

        if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && 
        board[ni][nj]==1){
            dfs(ni,nj,vis,board);
        }
    }
}
    int numEnclaves(vector<vector<int>>& board) {
        n=board.size();
        m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m));
        
        for(int i=0;i<n;i++)if(board[i][0]==1)dfs(i,0,vis,board);
        for(int i=0;i<n;i++)if(board[i][m-1]==1)dfs(i,m-1,vis,board);
        for(int i=0;i<m;i++)if(board[0][i]==1)dfs(0,i,vis,board);
        for(int i=0;i<m;i++)if(board[n-1][i]==1)dfs(n-1,i,vis,board);

        int cnt=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && board[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};