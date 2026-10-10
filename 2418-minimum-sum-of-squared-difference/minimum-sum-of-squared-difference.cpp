using ll=long long;

class Solution {
public:
    ll minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
        int n=a.size();

        ll k=(ll)k1+k2;
        vector<ll>c(1E5+1);

        for(int i=0;i<n;i++) c[abs(a[i]-b[i])]+=1;

        for(int i=1E5;i>0 && k;i--){
            ll x=min(c[i],k);
            c[i]-=x;
            c[i-1]+=x;
            k-=x;
        }

        ll ans=0;
        for(int i=1;i<=1E5;i++) ans+=c[i]*i*i;
        return ans;
    }
};