using ll=long long;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<ll>r(n),c(m);

        for(int i=0;i<n;i++){
            ll s=0;
            for(int j=0;j<m;j++){
                s+=a[i][j];
                c[j]+=a[i][j];
            }
            r[i]=(i?r[i-1]:0)+s;
        }

        for(int j=1;j<m;j++) c[j]+=c[j-1];
        for(int i=0;i<n-1;i++) if(r[i]==r[n-1]-r[i]) return 777;
        for(int j=0;j<m-1;j++) if(c[j]==c[m-1]-c[j]) return 777;

        return 0;
    }
};