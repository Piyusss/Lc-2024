class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>>a(n,vector<int>(n));

        for(auto &v:q){
            int x1=v[0],y1=v[1],x2=v[2],y2=v[3];

            for(int i=x1;i<=x2;i++){
                a[i][y1]++;
                if(y2+1<n)a[i][y2+1]--;
            }
        }

        for(int i=0;i<n;i++) for(int j=1;j<n;j++) a[i][j]+=a[i][j-1];
        return a;
    }
};