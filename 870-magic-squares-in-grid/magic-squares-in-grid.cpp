class Solution {
public:bool f(vector<vector<int>>& grid,int r,int c){

    unordered_set<int>st;
    for(int i=r;i<=r+2;i++){
        for(int j=c;j<=c+2;j++){
            int num=grid[i][j];
            if(num<1 || num>9 || st.count(num))return 0;
            else st.insert(num);
        }
    }
    
    int sum=grid[r][c] + grid[r][c+1] + grid[r][c+2];
    for(int i=0;i<3;i++){
        if(grid[i+r][c] + grid[i+r][c+1] + grid[i+r][c+2]!=sum)return 0;
    }
    for(int i=0;i<3;i++){
        if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i]!=sum)return 0;
    }
    if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=sum)return 0;
    if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=sum)return 0;

    return 1;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int res=0;

        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(f(grid,i,j))res++;
            }
        }

        return res;
    }
};