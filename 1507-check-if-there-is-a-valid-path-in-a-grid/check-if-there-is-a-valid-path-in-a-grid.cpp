class Solution {
public:

int n,m;

bool dfs(int i,int j,vector<vector<int>>&grid,int par_i,int par_j,vector<vector<int>>& vis){
    vis[i][j]=1;

    if(i==n-1 && j==m-1)return 1;

    if(grid[i][j]==1){

        //
        int ni=i;int nj=j+1;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==3 || grid[ni][nj]==5 || grid[ni][nj]==1) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            }
        }
        //

        //
        ni=i; nj=j-1;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==4 || grid[ni][nj]==6 || grid[ni][nj]==1) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //
        

    }

    else if(grid[i][j]==2){

        //
        int ni=i+1;int nj=j;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==5 || grid[ni][nj]==6 || grid[ni][nj]==2) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //

        //
         ni=i-1; nj=j;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==3 || grid[ni][nj]==4 || grid[ni][nj]==2) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //
        

    }

    else if(grid[i][j]==3){

        //
        int ni=i+1;int nj=j;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==2 || grid[ni][nj]==5 || grid[ni][nj]==6) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //

        //
         ni=i; nj=j-1;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==4 || grid[ni][nj]==6 || grid[ni][nj]==1) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //
        

    }

     else if(grid[i][j]==4){

        //
        int ni=i+1;int nj=j;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==2 || grid[ni][nj]==5 || grid[ni][nj]==6) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //

        //
         ni=i; nj=j+1;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==1 || grid[ni][nj]==3 || grid[ni][nj]==5) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //
        

    }

     else if(grid[i][j]==5){

        //
        int ni=i-1;int nj=j;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==2 || grid[ni][nj]==3 || grid[ni][nj]==4) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //

        //
         ni=i; nj=j-1;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==4 || grid[ni][nj]==6 || grid[ni][nj]==1) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //
        

    }

    else if(grid[i][j]==6){

        //
        int ni=i-1;int nj=j;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==2 || grid[ni][nj]==3 || grid[ni][nj]==4) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //

        //
         ni=i; nj=j+1;
        if(ni>=0 && nj>=0 && ni<n && nj<m && !(ni==par_i && nj==par_j)){
            if((grid[ni][nj]==1 || grid[ni][nj]==3 || grid[ni][nj]==5) && (!vis[ni][nj])){
                if(dfs(ni,nj,grid,i,j,vis))return 1;
            } 
        }
        //
        

    }

    
return 0;

}

    bool hasValidPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        if(dfs(0,0,grid,-1,-1,vis))return 1;
        return 0;
    }
};