class Solution {
public:

int cnt=0;

void f(int col,vector<string>&board,int n,vector<int> &leftRow,vector<int> &lowerDiagonal,vector<int> &upperDiagonal){
    if(col==n){
        cnt++;
        return;
    }
    
    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1+col-row]=1;

            f(col+1,board,n,leftRow,lowerDiagonal,upperDiagonal);

            board[row][col]='.';
            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1+col-row]=0;
        }
    }
}

    int totalNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        vector<int>leftRow(n,0),lowerDiagonal(2*n-1,0),upperDiagonal(2*n-1,0);
        f(0,board,n,leftRow,lowerDiagonal,upperDiagonal);
        return cnt;
    }
};