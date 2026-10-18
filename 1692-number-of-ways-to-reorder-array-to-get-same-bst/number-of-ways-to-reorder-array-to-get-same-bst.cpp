using ll=long long;
const int mod=1E9+7;

class Solution {
public:

    vector<vector<ll>>c;

    ll f(vector<int>&a){
        int n=a.size();
        if(n<=2) return 1;

        vector<int>x,y;

        for(int i=1;i<n;i++){
            if(a[i]<a[0]) x.push_back(a[i]);
            else y.push_back(a[i]);
        }

        ll ans=c[x.size()+y.size()][x.size()];
        ans=ans*f(x)%mod;
        ans=ans*f(y)%mod;

        return ans;
    }

    int numOfWays(vector<int>& a) {
        int n=a.size();
        c.assign(n+1,vector<ll>(n+1));

        for(int i=0;i<=n;i++){
            c[i][0]=1;
            for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }

        return (f(a)-1+mod)%mod;
    }
};