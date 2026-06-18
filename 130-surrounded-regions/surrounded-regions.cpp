class Solution {
public:

    int n,m;
    vector<pair<int,int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

    void dfs(int i,int j,vector<vector<char>>&board){
        board[i][j]='#';

        for(auto &c:dir){
            int ni=i+c.first;
            int nj=j+c.second;
            if(ni>=0 && ni<=n-1 && nj>=0 && nj<=m-1 && board[ni][nj]=='O') dfs(ni,nj,board);
        }

        return;
    }

    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();

        for(int j=0;j<m;j++) if(board[0][j]=='O') dfs(0,j,board);
        for(int j=0;j<m;j++) if(board[n-1][j]=='O') dfs(n-1,j,board);
        for(int i=0;i<n;i++) if(board[i][0]=='O') dfs(i,0,board);
        for(int i=0;i<n;i++) if(board[i][m-1]=='O') dfs(i,m-1,board);

        for(int i=0;i<=n-1;i++){
            for(int j=0;j<=m-1;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }

        return;
    }
};