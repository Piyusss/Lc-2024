class Solution {
public:
int n1,n2,m1,m2;
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

int flag=0;

void dfs(int i,int j,vector<vector<int>>&grid2,vector<vector<int>>&grid1){
    grid2[i][j]=0;
    if(grid1[i][j]==0)flag=1;

    for(auto &it:dir){
        int new_i=i+it[0];
        int new_j=j+it[1];

        if(new_i>=0 && new_j>=0 && new_i<n2 && new_j<m2 && grid2[new_i][new_j]==1){
            dfs(new_i,new_j,grid2,grid1);
        }
    }
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n1=grid1.size();
        m1=grid1[0].size();

        n2=grid2.size();
        m2=grid2[0].size();


        int cnt=0;
        for(int i=0;i<n2;i++){
            for(int j=0;j<m2;j++){
                if(grid2[i][j]==1){
                    dfs(i,j,grid2,grid1);
                    if(flag==0)cnt++;
                    flag=0;
                }
            }
        }
        return cnt;
    }
};