using ll=long long;

class Solution {
public:
    ll countCommas(ll n) {
        ll ans=0;
        for(ll x=1E3;x<=n;x*=1E3) ans+=n-x+1;
        return ans;
    }
};