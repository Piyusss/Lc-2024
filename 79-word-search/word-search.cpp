class Solution {
public:
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;

bool dfs(vector<vector<char>>&board,int i,int j,string &word,int idx){
    if(idx==word.length()-1)return 1;

    char temp=board[i][j];
    board[i][j]='$';

    for(auto &it:dir){
        int new_i=i+it[0];
        int new_j=j+it[1];
        
        if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && board[new_i][new_j]!='$' && board[new_i][new_j]==word[idx+1]){
            if(dfs(board,new_i,new_j,word,idx+1))return 1;
        }
    }
    board[i][j]=temp;
    return 0;
}
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        //now
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,i,j,word,0))return 1;
                }
            }
        }
        return 0;
    }
};