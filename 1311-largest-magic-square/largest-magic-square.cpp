class Solution {
public:

    using ll=long long;

    bool ok(int x,int y,int k,vector<vector<int>>& a, vector<vector<ll>>& r,vector<vector<ll>>& c){
        ll s=0;
        for(int i=0;i<k;i++)s+=a[x+i][y+i];

        ll t=0;
        for(int i=0;i<k;i++)t+=a[x+i][y+k-1-i];

        if(s!=t)return 0;

        for(int i=x;i<x+k;i++){
            ll v=r[i][y+k-1]-(y?r[i][y-1]:0);
            if(v!=s)return 0;
        }

        for(int j=y;j<y+k;j++){
            ll v=c[x+k-1][j]-(x?c[x-1][j]:0);
            if(v!=s)return 0;
        }

        return 1;
    }

    int largestMagicSquare(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        vector<vector<ll>>r(m,vector<ll>(n)),c(m,vector<ll>(n));

        for(int i=0;i<m;i++){
            ll s=0;
            for(int j=0;j<n;j++){
                s+=a[i][j];
                r[i][j]=s;
            }
        }

        for(int j=0;j<n;j++){
            ll s=0;
            for(int i=0;i<m;i++){
                s+=a[i][j];
                c[i][j]=s;
            }
        }

        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=1;i+k<=m&&j+k<=n;k++){
                    if(ok(i,j,k,a,r,c))ans=max(ans,k);
                }
            }
        }

        return ans;
    }
};