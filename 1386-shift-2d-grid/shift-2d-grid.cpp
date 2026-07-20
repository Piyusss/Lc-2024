class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& a,int k) {
        int m=a.size(),n=a[0].size();

        int x=(k/n)%m;
        int y=k%n;

        vector<vector<int>>r(m,vector<int>(n));

        for(int i=0;i<m;i++){
            int u=i+x+1;

            for(int j=0;j<n;j++){
                bool f=j+y<n;

                int v=j+y;
                if(v>=n) v-=n;

                int t=u-f;
                if(t>=m) t-=m;

                r[t][v]=a[i][j];
            }
        }

        return r;
    }
};