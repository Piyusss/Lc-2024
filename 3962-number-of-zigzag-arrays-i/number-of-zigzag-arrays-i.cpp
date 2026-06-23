using ll=long long;

class Solution {
public:
    int zigZagArrays(int n,int l,int r) {
        ll M=1e9+7,ans=0;

        vector<vector<ll>>d(2,vector<ll>(r+2)),nd(2,vector<ll>(r+2));

        for(int j=l;j<=r;j++){
            d[0][j]=1;
            d[1][j]=1;
        }

        for(int i=n-2;i>=0;i--){
            vector<ll>p(r+3),s(r+3);

            for(int j=l;j<=r;j++) p[j]=(p[j-1]+d[1][j])%M;
            for(int j=r;j>=l;j--) s[j]=(s[j+1]+d[0][j])%M;

            for(int j=l;j<=r;j++){
                nd[0][j]=p[j-1];
                nd[1][j]=s[j+1];
            }

            swap(d,nd);
        }

        for(int j=l;j<=r;j++) ans=(ans+d[0][j]+d[1][j])%M;
        return ans;
    }
};