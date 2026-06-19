class Solution {
public:

    bool f2(vector<vector<char>>&board,int row,int col){
        char c=board[row][col];
        int cnt1=0,cnt2=0,cnt3=0;

        for(int k=0;k<9;k++){
            if(board[k][col]==c) cnt1++; //column-validate
            if(board[row][k]==c) cnt2++; //row-validate
            if(board[3*(row/3)+(k/3)][3*(col/3)+(k%3)]==c) cnt3++; //sub-box-validate
        }
        if(cnt1>1 || cnt2>1 || cnt3>1) return 0;
        return 1;
    }

    bool f(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(!f2(board,i,j)) return 0;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board){
        return f(board);
    }
};