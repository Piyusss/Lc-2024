class Solution {
public:

    int n,m;
    vector<pair<int,int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&board){
        vis[i][j]=1;

        for(auto &c:dir){
            int ni=i+c.first;
            int nj=j+c.second;
            if(ni>=0 && ni<=n-1 && nj>=0 && nj<=m-1 && !vis[ni][nj] && board[ni][nj]=='O') dfs(ni,nj,vis,board);
        }

        return;
    }

    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
        }

        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }

        for(int i=1;i<=n-2;i++){
            for(int j=1;j<=m-2;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }

        return;
    }
};