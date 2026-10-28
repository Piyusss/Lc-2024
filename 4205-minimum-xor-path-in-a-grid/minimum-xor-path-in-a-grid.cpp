class Solution {
public:

    int f(vector<vector<int>>&a){
        int n=a.size(),m=a[0].size();
        vector<vector<bool>>d(m,vector<bool>(1024));

        d[0][a[0][0]]=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i&&!j) continue;

                vector<bool>c(1026);
                int x=a[i][j];

                for(int k=0;k<1024;k++) if((i&&d[j][k]) || (j&&d[j-1][k])) c[k^x]=1;
                d[j]=c;
            }
        }

        for(int i=0;i<1024;i++) if(d[m-1][i]) return i;
        return -1;
    }

    int minCost(vector<vector<int>>& grid) {
        return f(grid);
    }
};