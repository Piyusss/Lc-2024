class Solution {
public:
bool isValid(vector<vector<char>>&board,int row,int col,char c){
    int cnt=0;int cnt1=0;int cnt2=0;
    for(int i=0;i<9;i++){
        if(board[i][col]==c)cnt1++;
        if(board[row][i]==c)cnt2++;
        if(board[3*(row/3)+i/3][3*(col/3)+(i%3)]==c)cnt++;
    }
    if(cnt>1 || cnt1>1 || cnt2>1)return 0;
    return 1;
}
bool f(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.')continue;
            if(isValid(board,i,j,board[i][j])==false)return 0;
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board){
        return f(board);
    }
};