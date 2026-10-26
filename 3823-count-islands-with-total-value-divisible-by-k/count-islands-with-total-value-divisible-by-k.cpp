using ll=long long;

class Solution {
public:

    ll f(vector<vector<int>>&a,int i,int j){
        int m=a.size(),n=a[0].size();

        if(i<0 || j<0 || i>=m || j>=n || !a[i][j]) return 0;

        ll s=a[i][j];
        a[i][j]=0;

        s+=f(a,i+1,j);
        s+=f(a,i-1,j);
        s+=f(a,i,j+1);
        s+=f(a,i,j-1);

        return s;
    }

    int countIslands(vector<vector<int>>& grid,int k) {
        int m=grid.size(),n=grid[0].size(),ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    ll s=f(grid,i,j);
                    if(s%k==0) ans+=1;
                }
            }
        }

        return ans;
    }
};