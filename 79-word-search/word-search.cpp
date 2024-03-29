class Solution {
public:
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
bool dfs(vector<vector<char>>&board,int n,int m,int i,int j,string word,int idx){
    if(idx==word.length())return 1;
    if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='$' || board[i][j]!=word[idx])return 0;

    char temp=board[i][j];
    board[i][j]='$';
    for(auto &it:dir){
        int new_i=i+it[0];
        int new_j=j+it[1];
        if(dfs(board,n,m,new_i,new_j,word,idx+1))return 1;
    }
    board[i][j]=temp;
    return 0;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        //now
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,n,m,i,j,word,0))return 1;
                }
            }
        }
        return 0;
    }
};